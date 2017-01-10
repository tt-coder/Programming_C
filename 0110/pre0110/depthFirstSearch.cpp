#include <iostream>
#include <stack>
using namespace std;

int n,tm = 0;
int a[105][105],nxt[105],state[105],d[105],f[105]; // state:訪問状態,d:発見時刻,f:完了時刻

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
    stack<int> S;
    for(int i=0;i<n;i++){
        nxt[i] = 0;
    }
    S.push(t);
    state[t] = 1; // 訪問した
    d[t] = ++tm; // 発見時刻
    while(!S.empty()){
        u = S.top();
        v = getNext(u);
        if(v != -1){
            if(state[v] == 0){ // 次の頂点を訪問してなければ
                state[v] = 1; // 訪問
                d[v] = ++tm;
                S.push(v);
            }
        }else{ // 訪問してれば戻る
            S.pop();
            state[u] = 2; // 完了
            f[u] = ++tm; // 完了時刻
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
    
    dfsInit();
    for(int i=0;i<n;i++){
        if(state[i] == 0){
            dfs(i);
        }
    }
    for(int i=0;i<n;i++){
        cout << i+1 << " " << d[i] << " " << f[i] << endl;
    }
    return 0;
}