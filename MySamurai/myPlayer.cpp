#include "players.hpp"
#include <list>
#include <utility>

// 1~4 attack(SENW), 5~8 move, 9 hide
static const int COSTS[] = {0, 4, 4, 4, 4, 2, 2, 2, 2, 1};

struct MyPlayer: Player{

    void plan(GameInfo& info, SamuraiState &samurai, int budget, double merits){

    }

    void play(GameInfo& info){
        list<SamuraiState*> playable;
        list<SamuraiState*> underRecovery;
        for(SamuraiState& samurai: samuraiStates[0]){
            if(samurai.done == 0){
                if(samurai.recovery == 0){
                    playable.push_back(&samurai);
                }else{
                    underRecovery.push_back(&samurai);
                }
            }
        }
        if(!playable.empty()){
            for (SamuraiState* samurai: playable) {
	            plan(info, *samurai, 7, 0);
            }
            cout << bestSamurai->weapon;
            for (int action: bestPlay) {
	            cout << ' ' << action;
            }
        }else{
            SamuraiState* samurai = underRecovery.front();
            cout << samurai->weapon;
        }
        cout << " 0" << endl;
        cout.flush();
    }
};

Player* player = new MyPlayer();
