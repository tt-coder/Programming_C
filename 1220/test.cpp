#include <iostream>
#include <set>
using namespace std;
void print(set<int> S){
    for(set<int>::iterator it = S.begin();it!=S.end();it++){
        cout << " " << (*it);
    }
    cout << endl;
}

int main(){
    set<int> S;
    S.insert(10);
    print(S);
    S.erase(10);
    S.insert(2);
    if(S.find(2) == S.end()){
        cout << "Not fount" << endl;
    }
    return 0;
    // clear()
}
