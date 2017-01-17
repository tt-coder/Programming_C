#include <iostream>
#include <queue>
using namespace std;
#define NUM 100000000

int n;
int a[105][105],d[105];

void bfs(int t){
    int u;
    queue<int> q;
    q.push(t);
    for(int i=0;i<n;i++){
        d[i] = NUM;
    }
    d[t] = 0;
    while(!q.empty()){
        u = q.front();
        cout << u+1 << endl;
        q.pop();
        for(int v=0;v<n;v++){
            if(a[u][v] == 0) continue; // 繋がってなければスルー
            if(d[v] != NUM) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main(){
    int u,k,v;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){ // グラフの作成
        cin >> u >> k;
        u--;
        for(int j=0;j<k;j++){
            cin >> v;
            v--;
            a[u][v] = 1;
        }
    }
    bfs(0);
    /*
    for(int i=0;i<n;i++){
        cout << i+1 << " ";
        if(d[i] == NUM){
            cout << "-1" << endl;
        }else{
            cout << d[i] << endl;
        }
    }
    */
    return 0;
}