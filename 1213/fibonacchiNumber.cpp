/*
int fibonacchi(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return fibonacchi(i-2) + fibonacchi(i-1);
}
*/

/*
int fibonacchi(int n){
    if(n == 0 || n == 1){
        return F[n] = 1;
    }
    if(F[n] == 1)[
        return F[n];
    ]
    return F[n] = fibonacchi(i-2) + fibonacchi(i-1);
}
*/

/*
void fibonacchi(){
    F[0] = 1;
    F[1] = 1;
    for(int i=2;i<n;i++){
        F[i] = F[i-2] + F[i-1];
    }
}
*/

/*
#include <stdio.h>
int dp[50];

int fib(int n){
    if(n == 0 || n == 1){
        return dp[n] = 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fib(n-1) + fib(n-2);
}

int main(){
    int n,i;
    for(i=0;i<50;i++){
        dp[i] = -1;
    } 
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int F[50];
    F[0] = F[1] = 1;
    for(int i=2;i<=n;i++){
        F[i] = F[i-1] + F[i-2];
    }
    cout << F[n] << endl;0
}