#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 200000
#define INIT 1000000000

int main(){
    int n,maxk,mink,k[MAX];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> k[i];
    }
    mink = INIT;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mink > abs(k[i] - k[j])){
                mink = abs(k[i] - k[j]);
            }
        }
    }
    for(int i=a;i<=b;i++){
      if(maxm<=p[i]-p[i+1]){
        maxm=p[i]-p[i+1];
        id=i;
      }
    }
    cout << count << endl;
    return 0;
}