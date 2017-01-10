#include <iostream>
using namespace std;
#define NUM 10000000

int n;
int a[105][105];

void dijkstra(){
    int minv;
    int d[105],state[105];
    for(int i=0;i<n;i++){
        d[i] = NUM;
        state[i] = 0;
    }
    d[0] = 0;
    state[0] = 1;
    while(1){
        minv = NUM;
        int u = -1;
        for(int i=0;i<n;i++){
            if(minv > d[i] && state[i] != 2){
                u = i;
                minv = d[i];
            }
        }
        if(u == -1) break;
        state[u] = 2;
        for(int v=0;v<n;v++){
            if(state[v] != 2 && a[u][v] != NUM){
                if(d[v] > d[u] + a[u][v]){
                    d[v] = d[u] + a[u][v];
                    state[v] = 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << i << " ";
        if(d[i] == NUM){
            cout << "-1" << endl;
        }else{
            cout << d[i] << endl;
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = NUM;
        }
    }
    int k,c,u,v;
    for(int i=0;i<n;i++){
        cin >> u >> k;
        for(int j=0;j<k;j++){
            cin >> v >> c;
            a[u][v] = c;
        }
    }
    dijkstra();
    return 0;
}