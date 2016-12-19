#include <iostream>
#define MAX 1000000
using namespace std;

int count = 0,tmp = 0;

void solve(int *a, int n, int m, int p){
    if(p == n){
        tmp = 0;
        for(int i=0;i<n;i++){
            if(a[i] == 1){
                tmp++;
            }else if(a[i] == 0){
                tmp = 0;
            }
            if(tmp == m){
                count++;
                tmp = 0;
                break;
            }
        }
        return;
    }
    a[p] = 0;
    solve(a,n,m,p+1);
    a[p] = 1;
    solve(a,n,m,p+1);
}

int main(){
    int n,m,a[MAX];
    cin >> n >> m;
    solve(a,n,m,0);
    cout << count << endl;
}