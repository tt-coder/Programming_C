#include <iostream>
using namespace std;
int main(){
    int m,nmin,nmax,gap=0,ans=0;
    int a[205];
    cin >> m >> nmin >> nmax;
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    for(int i=nmin-1;i<nmax;i++){
      if(gap <= a[i] - a[i+1]){
        gap = a[i] - a[i+1];
        ans = i+2;
      }
    }
    cout << ans << endl;
    return 0;
}