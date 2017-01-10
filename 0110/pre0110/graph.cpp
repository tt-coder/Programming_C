#include <iostream>
using namespace std;

int main(){
    int n,u,k,v;
    int a[105][105];
    cin >> n;
    for(int i=0;i<n;i++){ // init
        for(int j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        cin >> u >> k;
        u--; // 0番目からとする
        for(int j=0;j<k;j++){
            cin >> v;
            v--;
            a[u][v] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=0) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}