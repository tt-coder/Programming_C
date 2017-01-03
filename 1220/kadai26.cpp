#include <iostream>
using namespace std;
#define MAX 500000
#define INIT 1000000000
int L[MAX/2+5], R[MAX/2+5];
int count = 0;

int merge(int A[], int n, int left, int mid, int right){
    int n1 = mid - left; // 左の個数
    int n2 = right - mid; // 右の個数
    int tmpCount = 0;
    for(int i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++){
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] = INIT;
    int i=0,j=0,k;
    for(k=left;k<right;k++){
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j];
            if(L[i]!=INIT){
                tmpCount += (n1+j-(k-left));
            }
            j++;
        }
    }
    count += tmpCount;
    return tmpCount;
}

void mergeSort(int A[], int n, int left, int right){
    int lcnt,rcnt,cnt;
    if(left + 1 < right){
        int mid = (left + right) / 2; //中間地点
        mergeSort(A, n, left, mid); // 左のソート
        mergeSort(A, n, mid, right); // 右のソート
        merge(A, n, left, mid, right);
        cout << count << endl;
    }
}


int main(){
    int A[MAX],n,i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> A[i];
    }
    mergeSort(A, n, 0, n);
    return 0;
}