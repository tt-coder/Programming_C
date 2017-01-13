#include "players.hpp"
#include <random>
#include <thread>

struct TimeoutPlayer: Player {
  default_random_engine generator;
  void play(GameInfo& info) {
    if (currentTurn >= 13) {
      this_thread::sleep_for(chrono::seconds(10));
    }
    SamuraiState* samurai;
    do {
      samurai = &samuraiStates[0][generator()%3];
    } while (samurai->done != 0);
    int power = 7;
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

Player* player = new TimeoutPlayer();
