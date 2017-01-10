#include <iostream>
#include <string>
#include <algorithm>
#define N 1005
using namespace std;

int solve(string x, string y){
    int z[N+1][N+1];
    int m = x.size();
    int n = y.size();
    int maxl = 0;
    x = ' ' + x;
    y = ' ' + y;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            z[i][j] = 0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i] == y[j]){
                z[i][j] = z[i-1][j-1] + 1;
            }else{
                z[i][j] = max(z[i-1][j], z[i][j-1]);
            }
            maxl = max(maxl, z[i][j]);
        }
    }
    return maxl;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << solve(s1,s2) << endl;
    return 0;
}