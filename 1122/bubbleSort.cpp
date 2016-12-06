// C++プログラム
#include <cstdio>
int a[1005],n,count = 0,countCmp = 0;

void print(){
    printf("%d\n", countCmp);
    printf("%d\n", count);
    for(int i=0;i<n;i++){
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void bubbleSort(){
    int i = 0,j,flag = 1,tmp;
    while(flag == 1){
        flag = 0;
        for(j=n-1;j>=i+1;j--){
            if(a[j]>a[j-1]){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                count++;
            }
            countCmp++;
        }
        i++;
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubbleSort();
    print();
    return 0;
}
