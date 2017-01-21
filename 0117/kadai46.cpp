#include <iostream>
using namespace std;
#define INIT 10000000

int n;
int a[105][105];

int solve(){
    int u,minv;
    int cost = 0;
    int dist[105],parent[105],state[105];
    for(int i=0;i<n;i++){
        dist[i] = INIT;
        parent[i] = -1;
        state[i] = 0;
    }
    dist[0] = 0;
    while(1){
        minv = INIT;
        u = -1;
        for(int i=0;i<n;i++){
            if(minv > dist[i] && state[i] != 2){
                u = i;
                minv = dist[i];
            }
        }
        if(u == -1) break;
        state[u] = 2;
        for(int v=0;v<n;v++){
            if(state[v] != 2 && a[u][v] != INIT){
                if(dist[v] > a[u][v]){
                    dist[v] = a[u][v];
                    parent[v] = u;
                    state[v] = 1;
                }
            }
        }
        cost = 0;
        for(int i=0;i<n;i++){
            if(parent[i] != -1){
                cost += a[i][parent[i]];
            }
        }
    }
    return cost;
}

int main(){
    int c;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          cin >> c;
          if(c == -1){
              a[i][j] = INIT;
          }else{
              a[i][j] = c;
          }
        }
    }
    cout << solve() << endl;
}