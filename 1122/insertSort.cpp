// C++プログラム
#include <cstdio>
int n, a[100],count=0;

void print(){
    printf("%d\n", count);
    for(int i=0;i<n;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",a[i]);
    }
    printf("\n");
}

void insertSort(){
    int i, j, tmp;
    for(i=1;i<n;i++){
        tmp = a[i];
        j = i - 1;
        while(j>=0 && a[j]<tmp){
            a[j+1] = a[j];
            j--;
            count++;
        }
        a[j+1] = tmp;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    insertSort();
    print();
    return 0;
}