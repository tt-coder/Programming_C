#include <stdio.h>

void print(int A[], int n){
    int i;
    for(i=0;i<n;i++){
        if(i>0){
            printf("");
        }
        printf("%d",A[i]);
    }
    printf("\n");
}

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
        print(A, n);
    }
}

int main(void){
    int i,j,n;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    print(a, n);
    insertSort(a, n);
    return 0;   
}