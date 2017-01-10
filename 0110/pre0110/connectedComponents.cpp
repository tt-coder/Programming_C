#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
int state[100005];
vector<int> G[100005];

void dfs(int r, int c){
    int u,v;
    stack<int> S;
    S.push(r);
    state[r] = c;
    while(!S.empty()){
        u = S.top();
        S.pop();
        for(int i=0;i<G[u].size();i++){
            v = G[u][i];
            if(state[v] == -1){
                state[v] = c;
                S.push(v);
            }
        }
    }
}

void assignColor(){
    int id = 1;
    for(int i=0;i<n;i++){
        state[i] = -1;
    }
    for(int u=0;u<n;u++){
        if(state[u] == -1){
            dfs(u, id++);
        }
    }
}

int main(){
    int s,t,m,q;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    assignColor();
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> s >> t;
        if(state[s] == state[t]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}