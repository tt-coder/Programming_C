#include <iostream>
#define MAX 1000000
using namespace std;

int count = 0,tmp = 0;
string str[MAX];

void solve(string *s, int n, int m, int p){
    if(p == n){
        tmp = 0;
        for(int i=0;i<n;i++){
            if(s[i] == "yes"){
                tmp++;
            }else if(s[i] == "no"){
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
    s[p] = "no";
    solve(s,n,m,p+1);
    s[p] = "yes";
    solve(s,n,m,p+1);
}

int main(){
    int n,m;
    cin >> n >> m;
    solve(str,n,m,0);
    cout << count << endl;
}