#include <iostream>
#define MAX 100000
using namespace std;

int A[MAX], n;

int partition(int p, int r){
    int x,i,j;
    x = A[p];
    i = p;
    for(j=p+1;j<=r;j++){
        if(A[j] < x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i],A[p]);
    return i;
}

int main(){
    int i,q;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> A[i];
    }
    q = partition(0, n-1);
    for(i=0;i<n;i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << q+1 << endl;
    return 0;
}