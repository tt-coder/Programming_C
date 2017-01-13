struct TurnPlay {
  vector <string> turnComments;
  int samurai;
  int responseTime;
  list <int> actions;
  int territories[6];
  TurnPlay(int samurai, list<int>& actions, int response, int territories[]);
  void writeOut(ostream& os);
};

struct GameLog {
  string gameName;
  vector <string> gameComments;
  string playerNames[2];
  int initialResponseTimes[2];
  int totalTurns;
  vector <TurnPlay> plays;
  void init(string gn, int totalTurns);
  void addTurnPlay(int samurai, list<int>& actions,
		   int reponse, int territories[]);
  void writeOut(ostream& os);
};

extern GameLog gameLog;
