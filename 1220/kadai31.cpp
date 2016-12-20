#include <iostream>
#define MAX 1000005
using namespace std;

int main(){
    int h,i,a[MAX];
    cin >> h;
    for(int i=1;i<=h;i++){
        cin >> a[i];
    }

    for(int i=1;i<=h;i++){
        cout << "node " << i << ": key = " << a[i] << ", ";
        if((i/2) >= 1){
            cout << "parent key = " << a[(i/2)] << ", ";
        }
        if((2*i) <= h){
            cout << "left key = " << a[(2*i)] << ", ";
        }
        if((2*i+1) <= h){
            cout << "right key = " << a[(2*i+1)] << ", ";
        }
        cout << endl;
    }
    return 0;
}