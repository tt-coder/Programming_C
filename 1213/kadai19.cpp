#include <iostream>
#define MAX 100005
using namespace std;

int a[MAX],n;

int partition(int p, int r){
    int x,i,j,t;
    x = a[r];
    i = p-1;
    for(j=p;j<r;j++){
        if(a[j] >= x){
            i++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[i+1];
    a[i+1] = a[r];
    a[r] = t;
    return i+1;
}

int main(){
    int i,q;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    q = partition(0, n-1);
    for(i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    for(i=0;i<n;i++){
        if(a[i] == n){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}