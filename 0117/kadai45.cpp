#include <iostream>
using namespace std;
#define H 10
#define W 10

char map[H][W];
int cost[H][W];
int cdnt[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; //上下右左

void solve(int x, int y){
	int now,nowX,nowY;
	now = cost[y][x]; // 今の場所のコスト
	if(now < 0) return;
	for(int i=0;i<4;i++){
		nowX = x + cdnt[i][0]; // 周りのコストを求める
		nowY = y + cdnt[i][1];
		if (nowX < 0 || nowY < 0 || nowX >= W || nowY >= H) continue; //座標オーバーは無視
		if (map[nowY][nowX] == '#') continue; // 壁は無視
		if (cost[nowY][nowX] < 0 || now + 1 < cost[nowY][nowX]) { // 移動
			cost[nowY][nowX] = now + 1;
			solve(nowX,nowY);
		}
	}
}

int main(){
	char c;
	int startX,startY,endX,endY;
	for(int i=0;i<H;i++){ // マップ読み込み
		for(int j=0;j<W;j++){
			cin >> c;
			map[i][j] = c;
			cost[i][j] = -1;
			if(c == 'S'){
				startX = j;
				startY = i;
				cost[i][j] = 0;
			}else if(c == 'G'){
				endX = j;
				endY = i;
			}
		}
	}
	solve(startX,startY);
	cout << cost[endY][endX] << endl;
}