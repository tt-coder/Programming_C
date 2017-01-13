#include "players.hpp"
#include <random>
#include <thread>

struct TooActivePlayer: Player {
  default_random_engine generator;
  void play(GameInfo& info) {
    int power = (13 <= currentTurn && currentTurn < 20 ? 10 : 7);
    SamuraiState* samurai;
    do {
      samurai = &samuraiStates[0][generator()%3];
    } while (samurai->done == 0);
    cout << samurai->weapon << ' ';
    while (power >= 2) {
      int action = generator()/1024%9 + 1;
      static const int required[] = {0, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1}; 
      if (required[action] <= power && info.isValid(*samurai, action)) {
	power -= required[action];
	cout << ' ' << action;
      }
    }
    cout << " 0" << endl;
    cout.flush();
    debug->flush();
  }
};

Player* player = new TooActivePlayer();
