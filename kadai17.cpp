#include <iostream>
using namespace std;

int comb(int n,int m){
    if(m==0){
        return 1;
    }else{
        return comb(n,m-1)*(n-m+1)/m;
    }
}

int main(){
    int n,m,count=0;;
    cin >> n >> m;
    for(int i=m;i<n;i++){
        count += comb(n,i);
    }
    cout << count << endl;
}