// C++プログラム
#include <cstdio>
int a[1005],n,count = 0;

void print(){
    printf("%d\n", count);
    for(int i=0;i<n;i++){
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void selectionSort(){
    int i,j,tmp,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i;j<n;j++){
            if(a[j]>a[min]){
                min = j;
            }
        }
        tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
        if(i != min){
            count++;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    selectionSort();
    print();
    return 0;
}
