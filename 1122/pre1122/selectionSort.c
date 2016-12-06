#include <stdio.h>
int n,count = 0;
int a[100];

void print(){
    int i;
    for(i=0;i<n;i++){
        if(i>0){
            printf("");
        }
        printf("%d",a[i]);
    }
    printf("\n");
}

void selectionSort(){
    int i,j,tmp,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
        if(i != min){
            count++;
        }
    }
}

int main(void){
    int i;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    selectionSort();
    print();
}