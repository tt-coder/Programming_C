#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define NUM 100000000

int n;
int a[105][105],d[105];
int nxt[105],state[105];

int getNext(int u){
    for(int v=nxt[u];v<n;v++){
        nxt[u] = v + 1;
        if(a[u][v] == 1) return v;
    }
    return -1;
}

void dfsInit(){
    for(int i=0;i<n;i++){
        state[i] = 0; // 訪問していない
        nxt[i] = 0;
    }
}

void dfs(int t){
    int u,v;
    bool isFirst = true;
    stack<int> S;
    for(int i=0;i<n;i++){
        nxt[i] = 0;
    }
    S.push(t);
    state[t] = 1; // 訪問した
    cout << "1";
    while(!S.empty()){
        u = S.top();
        v = getNext(u);
        if(isFirst == false){
            cout << " ";
        }else{
            cout << "1 ";
            isFirst = false;
        }
        if(v != -1){
            if(state[v] == 0){ // 次の頂点を訪問してなければ
                state[v] = 1; // 訪問
                cout << v+1;
                S.push(v);
            }
        }else{ // 訪問してれば戻る
            S.pop();
            state[u] = 2; // 完了
        }
    }
    cout << endl;
}

void bfs(int t){
    int u;
    bool isFirst = true;
    queue<int> q;
    q.push(t);
    for(int i=0;i<n;i++){
        d[i] = NUM;
    }
    d[t] = 0;
    while(!q.empty()){
        u = q.front();
        if(isFirst == false){
            cout << " ";
        }else{
            isFirst = false;
        }
        cout << u+1;
        q.pop();
        for(int v=0;v<n;v++){
            if(a[u][v] == 0) continue; // 繋がってなければスルー
            if(d[v] != NUM) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    cout << endl;
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
    dfsInit();
    for(int i=0;i<n;i++){
        if(state[i] == 0){
            dfs(i);
        }
    }
    return 0;
}