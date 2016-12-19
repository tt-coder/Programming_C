#include <cstdio>
#include <cstdlib>
#define MAX 2000005
#define MAX2 10005

int n;
int *a,*b;
int c[MAX2];
int max = 0;
int tmp[MAX2];

void countingSort(){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i+1]);
        if(max < a[i+1]){
            max = a[i+1];
        }
        c[a[i+1]]++;
        tmp[a[i+1]]++;
    }
    for(int i=1;i<=MAX2;i++){
        c[i] = c[i] + c[i-1];
    }
    for(int i=1;i<=n;i++){
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
}


int main(){
    scanf("%d",&n);
    a = (int*)malloc(sizeof(int) * n+1);
    b = (int*)malloc(sizeof(int) * n+1);
    for(int i=0;i<=MAX2;i++){
        c[i] = 0;
    }
    countingSort();
    for(int i=0;i<max+1;i++){
        if(i!=0) printf(" ");
        printf("%d",tmp[i]);
    } 
    printf("\n");
    for(int i=n;i>0;i--){
        if(i!=n) printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
}