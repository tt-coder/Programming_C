#include "samurai.hpp"

static void writeString(ostream& os, string s) {
  os << '"';
  for (char c: s) {
    if (c == '"' || c == '\\') os << '\\';
    os << c;
  }
  os << '"';
}

TurnPlay::TurnPlay(int samurai, list <int>& actions,
		   int response, int terr[]):
  samurai(samurai), actions(actions), responseTime(response) {
  copy_n(terr, 6, territories);
}

void TurnPlay::writeOut(ostream& os) {
  os << "    {" << endl
     << "      \"samurai\": " << samurai << ',' << endl
     << "      \"responseTime\": " << responseTime << ',' << endl
     << "      \"actions\": [ ";
  if (!actions.empty()) {
    os << actions.front();
    actions.pop_front();
    for (int a: actions) {
      os << ", " << a;
    }
  }
  os << " ]," << endl
     << "      \"territories\": [";
  for (int t = 0; t != 6; t++) {
    os << (t == 0 ? " " : ", ") << territories[t];
  }
  os << " ]" << endl
     << "    }";
}
  
void GameLog::init(string gn, int tt) {
  gameName = gn;
  playerNames[0] = firstPlayer->name;
  playerNames[1] = secondPlayer->name;  
  totalTurns = tt;
}

void GameLog::addTurnPlay
(int samurai, list <int>& actions, int response, int territories[]) {
  plays.emplace_back(samurai, actions, response, territories);
}

void GameLog::writeOut(ostream& os) {
  os << '{' << endl
     << "  \"title\": ";
  writeString(os, gameName);
  os << ',' << endl
     << "  \"playerNames\": [ ";
  writeString(os, playerNames[0]);  
  os << ", ";
  writeString(os, playerNames[1]);  
  os << "]," << endl
     << "  \"initialResponseTimes\": [ "
     << initialResponseTimes[0] << ", "
     << initialResponseTimes[1] << " ]," << endl
     << "  \"plays\": [";
  for (int tp = 0; tp != plays.size(); tp++) {
    if (tp != 0) os << ',';
    os << endl;
    plays[tp].writeOut(os);
  }
  os << endl
     << "  ]" << endl
     << "}" << endl;
}
