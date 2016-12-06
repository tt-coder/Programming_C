#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,q,time,endt = 0,t; // endt:そのプロセスが終わった時間
    string name;
    queue<pair<string, int>> qu;
    pair<string, int> tmp;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> name >> time;
        qu.push(make_pair(name,time));
    }
    while(!qu.empty()){
        tmp = qu.front();
        qu.pop();
        t = min(tmp.second, q); // 処理時間と必要時間を比べ、低い方を代入
        tmp.second -= t; // 処理したので引く
        endt += t; // 処理時間分加算
        if(tmp.second > 0){ // また終わってなければ再び入れる
            qu.push(tmp);
        }else{
            cout << tmp.first << " " << endt << endl;
        }
    }
    return 0;
}