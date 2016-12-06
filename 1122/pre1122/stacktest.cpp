#include <iostream>
#include <stack>
using namespace std;

int main(void){
    stack<int> S;
    S.push(3);
    S.push(7);
    S.push(1);
    cout << S.size() << " ";

    cout << S.top() << " ";
}