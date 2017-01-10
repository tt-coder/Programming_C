#include <iostream>
#define MAX 2000000
using namespace std;

int H,A[MAX+1];

void maxHeapify(int i){
    int l,r,largest;
    l = 2 * i; // 左
    r = 2 * i + 1; // 右
    if(l <= H && A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= H && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int main(){
    cin >> H;
    for(int i=1;i<=H;i++){
        cin >> A[i];
    }
    for(int i=H/2;i>=1;i--){
        maxHeapify(i);
    }
    for(int i=1;i<=H;i++){
        cout << " " << A[i];
    }
    cout << endl;
    return 0;
}