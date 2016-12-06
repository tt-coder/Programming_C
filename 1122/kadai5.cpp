#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

queue<pair<string, int>> qu;
queue<pair<string, int>> result;
pair<string, int> tmp;
pair<string, int> printQ[100005];

void printQueue(){
    int size = qu.size();
    for(int i=0;i<size;i++){
        printQ[i] = qu.front();
        qu.pop();
    }
    for(int i=size-1;i>=0;i--){
        cout << printQ[i].first << " " << printQ[i].second;
        cout << " ";
        qu.push(printQ[i]);
    }
    cout << endl;
}

void printResult(){
    int size = result.size();
    for(int i=0;i<size;i++){
        printQ[i] = result.front();
        result.pop();
    }
    for(int i=0;i<size;i++){
        cout << printQ[i].first << " " << printQ[i].second;
        cout << " ";
    }
    cout << endl;
}

int main(){
    int n,q,time,endt = 0,t; // endt:そのプロセスが終わった時間
    string name;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> name >> time;
        qu.push(make_pair(name,time));
    }
    printQueue();
    while(!qu.empty()){
        tmp = qu.front();
        qu.pop();
        t = min(tmp.second, q); // 処理時間と必要時間を比べ、低い方を代入
        tmp.second -= t; // 処理したので引く
        endt += t; // 処理時間分加算
        if(tmp.second > 0){ // また終わってなければ再び入れる
            qu.push(tmp);
            printQueue();
        }else{
            //printQueue();
            //cout << tmp.first << " " << endt << endl;
            tmp.second = endt;
            result.push(tmp);
        }
    }
    printResult();
    return 0;
}