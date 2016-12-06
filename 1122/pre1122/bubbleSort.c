#include <stdio.h>
int count = 0;

void print(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        if(i>0){
            printf("");
        }
        printf("%d",a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[], int n){
    int i = 0,j,flag = 1,tmp;
    while(flag == 1){
        flag = 0;
        i++;
        for(j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    print(a,n);
}

int main(void){
    int n,i,j;
    int a[100];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    bubbleSort(a,n);
    printf("%d\n", count);
}