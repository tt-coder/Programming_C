#include <iostream>
#define MAX 100000
#define SENTINEL 20000000000
using namespace std;

struct Card{
    char suit;
    int value;
};

int partition(Card A[], int n, int p, int r){
    int i,j;
    Card x,t;
    x = A[r];
    i = p - 1;
    for(j=p;j<r;j++){
        if(A[j].value <= x.value){
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i+1;
}

void quickSort(Card A[], int n, int p, int r){
    int q;
    if(p < r){
        q = partition(A,n,p,r);
        quickSort(A,n,p,q-1);
        quickSort(A,n,q+1,r);
    }
}

int main(){
    int n,i,v;
    Card A[MAX];
    char S[10];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> S >> v;
        A[i].suit = S[0];
        A[i].value = v;
    }
    quickSort(A,n,0,n);
    for(i=0;i<n;i++){
        cout << A[i].suit << " " << A[i].value << endl;
    }
}