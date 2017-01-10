#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int key;
    string command;
    priority_queue<int> pq;
    while(1){
        cin >> command;
        if(command == "end"){
            break;
        }else if(command == "insert"){
            cin >> key;
            PQ.push(key);
        }else if(command == "extract"){
            cout << PQ.top() << endl;
            PQ.pop();
        }
    }
    return 0;
}