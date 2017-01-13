#include "samurai.hpp"

GameLog gameLog;
GameState gameState;
BattleField battleField;
SamuraiState samuraiStates[2][6];
int turn;

Player* firstPlayer;
Player* secondPlayer;

NullStream nullStream;
ostream* dump = &nullStream;

char* dbPath;

char* commLogPath = nullptr;

static int firstPlayerId = -1;
static int secondPlayerId = -1;
int periods = 16;
string gameName = "";

static void helpMessage(char* argv[]) {
  cerr << "Usage: " << argv[0] <<
    " [<options>] [<first-player> <second-player>]\n"
    "   <first-player> and <second-player> are non-negative integers\n"
    "   specifying ID of players listed in the player databse\n"
    " Options are the following.\n"
    "  -h: obtains this help message\n"
    "  -g<string>: specifies game name\n"
    "  -s<path>: specifies AI player database path\n"
    "  -m<path>: duplicates messages to AI program\n"
    "    Output path for player N is <path>+N\n"
    "  -p<#periods>: specifies the number of periods of the game\n"
    "  -d: dumps game process to stderr\n"
    "  -d<path>: dumps game process to <path>\n"
    "The following can be specified instead of payer IDs.\n"
    "  -A<command>: invocation command for a player\n"
    "  -P<command>: command for posing a player\n"
    "  -U<command>: command for resuming a player\n"
    "  -N<name>: nickname for a player\n"
    "Options -a, -p, -u, -n should be given twice for two players.\n";
}

[[noreturn]]
static void invalidOption(char* argv[], int k,
			  string msg = "Invalid option") {
  throw ErrorReport(msg + ": " + argv[k]
		    + "\n  -h for further help on options");
}

static int numericalArg(char* s) {
  int v = 0;
  char* p = s;
  while (isdigit(*p)) {
    v += 10*v + *p - '0';
    p++;
  }
  if (*p != '\0') {
    throw ErrorReport("Non-numeric argument specified: "+string(s));
  }
  return v;
}

static char* stringArg(char* argv[], int k, const char* errmsg) {
  char* arg = argv[k] + 2;
  if (*arg == 0) invalidOption(argv, k, errmsg);
  return arg;
}

static bool dbUsed;
static char* invocation[2];
static char* pauseCommand[2];
static char* resumeCommand[2];
static char* playerName[2] = {nullptr, nullptr};

static char* controlArg(char* argv[], int k, const char* optName,
			char* argStr[], int& argIndex) {
  char* arg = argv[k] + 2;
  if (*arg == 0) {
    string msg = string("Argument for not specified for ") + optName;
    invalidOption(argv, k, msg.c_str());
  }
  if (argIndex == 2) invalidOption(argv, k, "Too many option specified");
  argStr[argIndex++] = arg;
}

static void processCommandLine(int argc, char* argv[]) {
  int k = 1;
  int invokeIndex = 0;
  int pauseIndex = 0;
  int resumeIndex = 0;
  int nameIndex = 0;
  while (k != argc) {
    if (*argv[k] != '-') break;
    char* option = argv[k] + 1;
    switch (option[0]) {
    case 'g':
      gameName = string(stringArg(argv, k, "Game name not specified"));
      break;
    case 's':
      dbPath = stringArg(argv, k, "Samurai DB file not specified");
      break;
    case 'p':
      if (option[1] == 0)
	invalidOption(argv, k, "Number of periods not specified");
      periods = atoi(option+1);
      break;
    case 'd':
      if (option[1] == 0) {
	dump = &cerr;
      } else {
	dump = new ofstream(option+1);
	if (!dump->good()) 
	  throw ErrorReport(string("Failed to open dump file ") + (option+1));
      }
      break;
    case 'm': {
      if (option[1] == 0) 
	invalidOption(argv, k, "Interface dump file name not specified");
      commLogPath = option+1;
      break;
    }
    case 'h':
      helpMessage(argv);
      break;
    case 'A':
      controlArg(argv, k, "-A", invocation, invokeIndex);
      break;
    case 'P':
      controlArg(argv, k, "-P", pauseCommand, pauseIndex);
      break;
    case 'U':
      controlArg(argv, k, "-U", resumeCommand, resumeIndex);
      break;
    case 'N':
      controlArg(argv, k, "-N", playerName, nameIndex);
      break;
    default:
      invalidOption(argv, k);
    }
    k += 1;
  }
  dbUsed = (invokeIndex == 0 && pauseIndex == 0 && resumeIndex == 0);
  if (dbUsed) {
    if (k+2 != argc) {
      throw ErrorReport("Too few or too many command arguments");
    }
    firstPlayerId = numericalArg(argv[k]);
    secondPlayerId = numericalArg(argv[k+1]);
  } else {
    if (invokeIndex != 2 || pauseIndex != 2 || resumeIndex != 2) {
      throw ErrorReport("Options -A, -P, -U all have to be specified twice");
    }
    if (k != argc) {
      throw ErrorReport("Too many arguments");
    }
  }
}

string playerDirPath;
map <int, DBEntry> playerDB;

static void readPlayerDB() {
  static const int DBLINESIZEMAX = 1024;
  char lineBuf[DBLINESIZEMAX+1];
  char* dbStr = getenv("SAMURAIPLAYERSDB");
  string dbPath =
    (dbStr == nullptr ? string("players/players.txt") : string(dbStr));
  ifstream dbs(dbPath);
  if ((dbs.rdstate() & ifstream::failbit) != 0) {
    throw ErrorReport("Failed to open " + dbPath);
  }
  dbs.getline(lineBuf, 1024);
  playerDirPath = string(lineBuf);
  if (playerDirPath.back() != '/') {
    playerDirPath += '/';
  }
  while (!dbs.eof()) {
    dbs.getline(lineBuf, DBLINESIZEMAX);
    if (lineBuf[0] != '\0') {
      DBEntry entry = DBEntry(lineBuf, playerDirPath);
      playerDB[entry.id] = entry;
    }
  }
}

int main(int argc, char* argv[]) {
  try {
    turn = -1;
    processCommandLine(argc, argv);
    if (dbUsed) {
      readPlayerDB();
      if (playerDB.count(firstPlayerId) == 0) {
	throw ErrorReport("Player not in DB: " + firstPlayerId);
      }
      if (playerDB.count(secondPlayerId) == 0) {
	throw ErrorReport("Player not in DB: " + secondPlayerId);
      }
      firstPlayer = new Player(playerDB[firstPlayerId], 0);
      secondPlayer = new Player(playerDB[secondPlayerId], 1);
    } else {
      firstPlayer = new
	Player(playerName[0], invocation[0],
	       pauseCommand[0], resumeCommand[0], 0);
      secondPlayer = new
	Player(playerName[1], invocation[1],
	       pauseCommand[1], resumeCommand[1], 1);
    }
    firstPlayer->initCommunication(commLogPath);
    firstPlayer->initialHandShake();
    secondPlayer->initCommunication(commLogPath);
    secondPlayer->initialHandShake();
    gameLog.init(gameName, 6*periods);
    gameState.init();
    turn = 0;
    *dump << "### Initial State" << endl;
    gameState.dumpState();
    for (int p = 0; p != periods; p++) {
      for (int a = 0; a != 2; a++) {
	for (int w = 0; w != 3; w++) {
	  gameState.samuraiStates[a][w].alreadyPlayed = false;
	}
      }
      for (int s = 0; s != 3; s++) {
	firstPlayer->sendTurnInfo();
	firstPlayer->receiveActionCommands();
	*dump << "### After Turn " << turn << endl;
	gameState.dumpState();
	turn++;
	secondPlayer->sendTurnInfo();
	secondPlayer->receiveActionCommands();
	*dump << "### After Turn " << turn << endl;
	gameState.dumpState();
	turn++;
      }
    }
    for (int a = 0; a != 2; a++) {
      firstPlayer->finalize();
      secondPlayer->finalize();
    }
    gameLog.writeOut(cout);
    return 0;
  } catch (ErrorReport err) {
    cerr << err.msg << endl;
    if (turn < 0) {
      cerr << "Before game starts" << endl;
    } else {
      cerr << "At turn " << turn << endl;
    }
    return -1;
  }
}
