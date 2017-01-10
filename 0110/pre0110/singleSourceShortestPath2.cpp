#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 10000
#define NUM 100000000

int n;
vector<pair<int, int>> adj[MAX];

void dijkstra(){
    priority_queue<pair<int,int>> PQ;
    int state[MAX];
    int d[MAX];
    for(int i=0;i<n;i++){
        d[i] = NUM;
        state[i] = 0;
    }
    d[0] = 0;
    PQ.push(make_pair(0,0));
    state[0] = 1;
    while(!PQ.empty()){
        pair<int,int> f = PQ.top();
        PQ.pop();
        int u = f.second;
        state[u] = 2;
        if(d[u] < f.first * (-1)) continue;
        for(int j=0;j<adj[u].size();j++){
            int v = adj[u][j].first;
            if(state[v] == 2) continue;
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v]*(-1),v));
                state[v] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << i << " ";
        if(d[i] == NUM){
            cout << NUM << endl;
        }else{
            cout << d[i] << endl;
        }
    }
}

int main(){
    int k,u,v,c;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> u >> k;
        for(int j=0;j<k;j++){
            cin >> v >> c;
            adj[u].push_back(make_pair(v,c));
        }
    }
    dijkstra();
}