#include "players.hpp"
#include <unistd.h>
#include <cstdlib>
#include <fstream>

int playOrder;
int totalTurns = 96;
int currentTurn;
int field[15][15];

ostream* debug;

char getChar() {
  return cin.get();
}

int getInt() {
  char c;
  do {
    c = getChar();
  } while (isspace(c));
  int v = 0;
  bool negate = (c == '-');
  if (negate) c = getChar();
  do {
    v = 10*v + c - '0';
    c = getChar();
  } while (!isspace(c));
  if (negate) v = -v;
  return v;
}

SamuraiState samuraiStates[2][3];

static const int homes[2][3][2] = {
  {{ 0, 0}, { 0, 7}, {7, 0}},
  {{14,14}, {14, 7}, {7,14}}
};

void SamuraiState::initSamuraiState(int a, int w) {
  weapon = w;
  int s = (playOrder == a ? 0 : 1);
  homeX = homes[s][w][0];
  homeY = homes[s][w][1];
  x = getInt();
  y = getInt();
  done = getInt();
  hidden = getInt();
  recovery = getInt();
  *debug << "# Samurai with weapon " << weapon << "@(" << x << "," << y << ")"
	 << " Done: " << done
	 << " Hidden: " << hidden
	 << " Recovery: " << recovery << endl;
}

GameInfo::GameInfo() {
  playOrder = getInt();
  cout << 0 << endl;
  debug->flush();
}

void GameInfo::readTurnInfo() {
  currentTurn = getInt();
  *debug << "# Turn = " << currentTurn << endl;
  if (currentTurn < 0) exit(0);
  for (int a = 0; a != 2; a++) {
    for (int w = 0; w != 3; w++) {
      samuraiStates[a][w].initSamuraiState(a, w);
    }
  }
  *debug << "### FIELD ###" << endl;
  for (int y = 0; y != height; y++) {
    for (int x = 0; x != width; x++) {
      field[x][y] = getInt();
      *debug << ' ' << field[x][y];
    }
    *debug << endl;
  }
}

bool GameInfo::isValid(SamuraiState& ss, const int action) const {
  return ss.isValidAction(action);
}

bool SamuraiState::isValidAction(const int action) const {
  // Cannot do anything under recovery
  if (recovery != 0) return false;
  switch (action) {
  case 1: case 2: case 3: case 4:
    // Occupation
    // Can occupy when not hidden
    return hidden == 0;
  case 5: case 6: case 7: case 8: {
    // Moving
    int nx = x;
    int ny = y;
    switch (action) {
    case 5: ny += 1; break;
    case 6: nx += 1; break;
    case 7: ny -= 1; break;
    case 8: nx -= 1; break;
    }
    // Cannot go out of the field
    if (nx < 0 || width <= nx || ny < 0 || height <= ny) return false;
    // Cannot enter enemy territory while hidden
    if (hidden != 0 && 3 <= field[nx][ny]) return false;
    for (int a = 0; a != 2; a++) {
      for (SamuraiState& ss: samuraiStates[a]) {
	// When not hidden, cannot share a section with another apparent samurai
	if (hidden == 0 && nx == ss.x && ny == ss.y && ss.hidden == 0)
	  return false;
	// Cannot enter the home posstions of other samurai
	if (&ss != this && nx == ss.homeX && ny == ss.homeY)
	  return false;
      }
    }
    return true;
  }
  case 9:
    if (hidden == 0) {
      // Hide
      // Cannot only hide itself in the territory
      if (3 <= field[x][y]) return false;
    } else {
      // Expose
      for (int a = 0; a != 2; a++) {
	for (SamuraiState& ss: samuraiStates[a]) {
	  // Cannot expose itself in a section with another apparent samurai
	  if (&ss != this &&
	      ss.hidden == 0 && x == ss.x && y == ss.y)
	    return false;
	}
      }
    }
    return true;
  default:
    *debug << "Invalid action " << action << " tried" << endl;
    exit(1);
  }
}

void rotate(int direction, int x0, int y0, int& x, int& y) {
  switch (direction) {
  case 0: x = x0; y = y0; break;
  case 1: x = y0; y = -x0; break;
  case 2: x = -x0; y = -y0; break;
  case 3: x = -y0; y = x0; break;
  }
}

static const int osize[3] = {4, 5, 7};

static const int ox[3][7] = {
  { 0, 0, 0, 0},
  { 0, 0, 1, 1, 2},
  {-1,-1,-1, 0, 1, 1, 1}};

static const int oy[3][7] = {
  { 1, 2, 3, 4},
  { 1, 2, 0, 1, 0},
  {-1, 0, 1, 1, 1, 0,-1}}; 

FieldUndo::FieldUndo(int* sect): section(sect), state(*section) {}
void FieldUndo::apply() { *section = state; }

SamuraiUndo::SamuraiUndo(SamuraiState* who): ss(who) {
  x = who->x; y = who->y; hidden = who->hidden;
}
void SamuraiUndo::apply() {
  ss->x = x; ss->y = y; ss->hidden = hidden;
}

void Undo::recField(int* sect) { fieldUndo.emplace_front(sect); }
void Undo::recSamurai(SamuraiState* ss) {
  samuraiUndo.emplace_front(ss);
}

void Undo::apply() {
  for (FieldUndo& u: fieldUndo) u.apply();
  for (SamuraiUndo& u: samuraiUndo) u.apply();
}

void GameInfo::tryAction(SamuraiState& samurai, int action, Undo& undo, 
			 int& territory, int& injury, int& hiding) {
  territory = injury = hiding = 0;
  int weapon = samurai.weapon;
  switch (action) {
  case 1: case 2: case 3: case 4: {
    // Occupy
    for (int k = 0; k != osize[weapon]; k++) {
      int xx, yy;
      rotate(action-1, ox[weapon][k], oy[weapon][k], xx, yy);
      xx += samurai.x; yy += samurai.y;
      if (0 <= xx && xx < width && 0 <= yy && yy < height) {
	for (int a = 0; a != 2; a++) {
	  for (SamuraiState& ss: samuraiStates[a]) {
	    if (ss.homeX == xx && ss.homeY == yy) goto ISAHOME;
	  }
	}
	{
	  int current = field[xx][yy];
	  if (current == 8) {
	    // unoccupied
	    territory += 1;
	  } else if (current >= 3) {
	    // opponent's territory
	    territory += 2;
	  }
	  for (SamuraiState& ss: samuraiStates[1]) {
	    if (ss.x == xx && ss.y == yy) {
	      undo.recSamurai(&ss);
	      ss.x = ss.homeX;
	      ss.y = ss.homeY;
	      injury++;
	      ss.hidden = 0;
	    }
	  }
	  undo.recField(&field[xx][yy]);
	}
      ISAHOME:;
      }
    }
    break;
  }
  case 5: case 6: case 7: case 8: {
    // Move
    static const int dx[] = { 0, 1, 0, -1 };
    static const int dy[] = { 1, 0, -1, 0 };
    undo.recSamurai(&samurai);
    samurai.x += dx[action-5];
    samurai.y += dy[action-5];
    break;
  }
  case 9:
    if (samurai.hidden == 0) {
      // Hide
      undo.recSamurai(&samurai);
      samurai.hidden = 1;
      hiding += 1;
      break;
    } else {
      // Expose
      undo.recSamurai(&samurai);
      samurai.hidden = 0;
      hiding -= 1;
      break;
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc == 2 && strcmp(argv[1], "-d") == 0) {
    debug = &cerr;
  } else {
    debug = new ofstream("/dev/null");
  }
  GameInfo info;
  while (true) {
    info.readTurnInfo();
    player->play(info);
  }
}
