#include <iostream>
#define MAX 100005
using namespace std;

int a[MAX],n,count = 0;

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
    count++;
    return i+1;
}

void quickSort(int p, int r){
    int q;
    if(p < r){
        q = partition(p,r);
        quickSort(p,q-1);
        quickSort(q+1,r);
    }
}

int main(){
    int i,q;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    count--;
    quickSort(0,n);
    for(i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}