#include <iostream>
using namespace std;
#define MAX 105
long long int dp[MAX];

long long int fib(int n){
    if(n == 0){
        return dp[n] = 1;
    }
    if(n == 1){
        return dp[n] = 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fib(n-1) + fib(n-2);
}

int main(){
    int n,i;
    for(i=0;i<MAX;i++){
        dp[i] = -1;
    }
    cin >> n;
    fib(n);
    for(int i=0;i<MAX;i++){
        if(dp[i]!=-1){
            if(i!=0) cout << " ";
            cout << dp[i];
        }else{
            break;
        }
    }
    cout << endl;
    return 0;
}