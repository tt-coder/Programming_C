#include <iostream>
#include <cstdio>
using namespace std;

struct Num{
    int order;
    int value;
};
int n;
Num *a;
int *b;

void insertSort(int A[], int n){
    int i, j, tmp;
    for(i=1;i<n;i++){
        tmp = A[i];
        j = i - 1;
        while(j>=0 && A[j]>tmp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = tmp;
    }
}

int main(){
    int maxValue,minValue,maxTime,minTime;
    int k = 0;
    cin >> n;
    a = (Num *)malloc(n);
    b = (int *)malloc(n*10);
    for(int i = 0;i<n;i++){
        a[i].order = i;
        cin >> a[i].value;
    }

    for(int i = 0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            b[k] = a[j].value - a[i].value;
            cout << b[k] << endl;
            k++;
        }
    }

    insertSort(b,k);
    //cout << b[k-1] << endl;
    
}