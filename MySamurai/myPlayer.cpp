#include "players.hpp"
#include <cmath>
#include <list>
#include <utility>

// 1~4 attack(SENW), 5~8 move, 9 hide
static const int COSTS[] = {0, 4, 4, 4, 4, 2, 2, 2, 2, 1};
int newLimit;
double evalValue[3] = {1.0,0.1,0.1};
int infoValue[3] = {};
int dxdy[4] = {1,2,3,4};
double current,maxValue;
list<int> bestPlay;
list<int> currentPlay;
SamuraiState* bestSamurai;
struct MyPlayer: Player{

    void analyzeSamurai(){
        int dist,minDist=1000;
        int minPosX,minPosY;
        int dir;
        SamuraiState samurai,enemy;
        for(int i=0;i<2 && minDist==0;i++){
            for(int j=0;j<3;j++){
                samurai = samuraiStates[i][j];
                int posX = samurai.x;
                int posY = samurai.y;
                if(i==0){
                    for(int k=0;k<3;k++){
                        enemy = samuraiStates[1][j];
                        int enemyPosX = enemy.x;
                        int enemyPosY = enemy.y;
                        dist = sqrt(pow(posX - enemyPosX,2) - pow(posY - enemyPosY,2));
                        if(dist < minDist){
                            minDist = dist;
                            minPosX = enemyPosX;
                            minPosY = enemyPosY;
                        }
                    }
                    if(minPosX - posX > 0){
                        dir = dxdy[2];
                    }else if(minPosX - posX < 0){
                        dir = dxdy[3];
                    }else if(minPosX - posX == 0){
                        if(minPosY - posY > 0){
                            dir = dxdy[0];
                        }else{
                            dir = dxdy[1];
                        }
                    }
                }
            }
            setValue(dir);
        }
    }

    int evaluation(){
        int value = 0;
        analyzeSamurai();
        for(int i=0;i<3;i++){
            value += infoValue[i]*evalValue[i];
        }
        return value;
    }

    void findBest(GameInfo& info, SamuraiState &samurai, int limit, double weight){
        for(int action = 1;action != 10;action++){
            if(COSTS[action] <= limit && info.isValid(samurai,action)){
                currentPlay.push_back(action);
                Undo undo;
                info.tryAction(samurai, action, undo, infoValue[0], infoValue[1], infoValue[2]);
                current = weight + evaluation();
                if(current > maxValue){
                    maxValue = current;
                    bestPlay = currentPlay;
                    bestSamurai = &samurai;
                }
                newLimit = limit-COSTS[action];
                findBest(info, samurai, newLimit, current);
                undo.apply();
                currentPlay.pop_back();
            }
        }
    }

    void setValue(int dir){
        Undo u;
        switch(dir){
            case 1:
                for(int i=0;i<3;i++){
                    evalValue[i] = infoValue[i]*0.1;
                }
                u.apply();
                break;
            case 2:
                for(int i=0;i<3;i++){
                    evalValue[i] = infoValue[i]*0.125;
                }
                u.apply();
                break;
            case 3:
                for(int i=0;i<3;i++){
                    evalValue[i] = infoValue[i]*0.15;
                }
                u.apply();
                break;
            case 4:
                for(int i=0;i<3;i++){
                    evalValue[i] = infoValue[i]*0.175;
                }
                u.apply();
                break;
            default:
                break;
        }
    }

    void initGame(){
        maxValue = -1;
        bestPlay.clear();
        currentPlay.clear();
    }

    void play(GameInfo& info){
        list<SamuraiState*> playable;
        list<SamuraiState*> underRecovery;
        initGame();
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
	            findBest(info, *samurai, 7, 0);
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
