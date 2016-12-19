#include <iostream>
using namespace std;
#define MAX 500000
#define INIT 2000000000
int L[MAX/2+2], R[MAX/2+2];
int count = 0;

void merge(int A[], int n, int left, int mid, int right){
    int n1 = mid - left; // 左の個数
    int n2 = right - mid; // 右の個数
    for(int i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    L[n1] = INIT;
    R[n2] = INIT;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i] <= R[j]){
            A[k] = R[i++];
        }else{
            A[k] = L[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right){
    if(left + 1 < right){
        count++;
        int mid = (left + right) / 2; //中間地点
        mergeSort(A, n, left, mid); // 左のソート
        mergeSort(A, n, mid, right); // 右のソート
        merge(A, n, left, mid, right);
    }
}

int main(){
    int A[MAX],n,i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> A[i];
    }
    mergeSort(A, n, 0, n);
    for(i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}