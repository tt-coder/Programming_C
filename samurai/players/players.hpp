#include <iostream>
#include <cstring>
#include <list>

using namespace std;

const int width = 15;
const int height = 15;
const int recoveryTurns = 18;

extern int field[width][height];
extern int playOrder;
extern int totalTurns;
extern int currentTurn;

extern ostream* debug;

void rotate(int direction, int x0, int y0, int& x, int& y);

struct SamuraiState {
  int homeX, homeY;
  int weapon;
  int x, y;
  int done;
  int hidden;
  int recovery;
  void initSamuraiState(int a, int w);
  bool isValidAction(const int action) const;
};

extern SamuraiState samuraiStates[2][3];

struct FieldUndo {
  int *section;
  int state;
  FieldUndo(int* sect);
  void apply();
};

struct SamuraiUndo {
  SamuraiState* ss;
  int x, y;
  int hidden;
  SamuraiUndo(SamuraiState* ss);
  void apply();
};

struct Undo {
  list<FieldUndo> fieldUndo;
  list<SamuraiUndo> samuraiUndo;
  void recField(int* sect);
  void recSamurai(SamuraiState* si);
  void apply();
};

struct GameInfo {
  GameInfo();
  void readTurnInfo();
  bool isValid(SamuraiState& ss, int action) const;
  void tryAction(SamuraiState& samurai, int action, Undo& undo,
		 int& territory, int& injury, int& hiding);
};

struct Player {
  virtual void play(GameInfo& info) = 0;
};

extern Player* player;
