#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <errno.h>
#include <unistd.h>
#include <cctype>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

#include "log.hpp"
#include "teestream.hpp"

const int initialTimeLimit = 10000;
const int responseTimeLimit = 200;
const int fieldWidth = 15;
const int fieldHeight = 15;
const int recoveryTurns = 18;
const int turnBudget = 7;
const int visibleDistance = 5;

extern const int homeX[2][3];
extern const int homeY[2][3];

extern int periods;
extern int turn;
extern ostream* dump;

struct ErrorReport {
  string msg;
  ErrorReport(string s);
};

struct Coordinates {
  const int x;
  const int y;
  Coordinates(int x, int y);
  Coordinates north() const;
  Coordinates south() const;
  Coordinates east() const;
  Coordinates west() const;
  Coordinates operator+(const Coordinates c) const;
  Coordinates rotate(const int direction) const;
  string toString() const;
  bool operator==(const Coordinates another) const;
};

struct CoordHash {
  size_t operator()(const Coordinates& c) const;
};

struct Section;

struct FieldMap: unordered_map <Coordinates, Section*, CoordHash> {
  Section* locate(Coordinates p);
};

struct Player;
struct SamuraiState;
struct GameState;

struct Section {
  const Coordinates coords;
  int state;		      // -1: free; s>=0: occupied by samurai s
  int homeOf;		      // Home of which samurai; -1 if of none
  int population;
  SamuraiState* apparent;
  Section *neighbors[4];
  Section(Coordinates coords);
  void setNeighbors(FieldMap& map);
  void leave(SamuraiState* s);
  void arrive(SamuraiState* s);
  void occupy(int sid);
  string toString() const;
};

extern ostream& operator<<(ostream& os, Section& s);

struct BattleField {
  FieldMap map;
  BattleField();
  Section* section(int x, int y);
  void occupy(SamuraiState& samurai, int direction, Section& pos);
};

extern BattleField battleField;

static const char* DIRECTIONS[] =
  { "south", "east", "north", "west" };

struct DBEntry {
  int id;
  int side;
  string name;
  string progPath;
  string invocation;
  DBEntry() {};
  DBEntry(char *buf, string dirPath);
};

extern map<int, DBEntry> playerDB;

struct Player {
  bool autoPlay;
  int side;
  string name;
  string progPath;
  string invocation;
  string pause;
  string resume;
  pid_t processId;
  string dirPath;
  string toAIpath;
  string fromAIpath;
  ostream* toAI;
  istream* fromAI;
  int response;
  bool alive;
  bool done;
  void initCommunication(char* logPath);
  void initialHandShake();
  void receiveAcknowledgement();
  void sendTurnInfo();
  void receiveActionCommands();
  void finalize();
  Player(DBEntry& entry, int side);
  Player(char* name, char* invoke, char* pause, char* resume, int side);
};

extern Player* firstPlayer;
extern Player* secondPlayer;

extern string playerDirPath;

struct SamuraiState {
  int side;
  int weapon;
  Section* position;
  Section* home;
  int curedAt;
  bool alive;
  bool hidden;
  bool alreadyPlayed;
  string dirname;
  queue<int> actions;

  void init(BattleField& field, int side, int weapon);
  bool move(int direction);
  bool occupy(int direction);
  bool hideAppear();
  void house(BattleField& field);
  void injure(BattleField& field);
};
  
static const char* WEAPONS[] =
  { "spear", "swords", "battleaxe" };

extern SamuraiState samuraiState;

struct GameState {
  SamuraiState samuraiStates[2][3];
  GameState() {};
  void init();
  void dumpState();
};

extern GameState gameState;

ostream& operator<<(ostream& os, const Coordinates& coord);

void receiveFromAI(istream& is, GameState& gameState,
		   const int side, const int weapon,
		   ostream& log, int turn);

