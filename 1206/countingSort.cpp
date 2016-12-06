#include <cstdio>
#include <cstdlib>
#define MAX 2000005
#define MAX2 10005

int n;
int *a,*b;
int c[MAX2];

void countingSort(){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i+1]);
        c[a[i+1]]++;
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
    for(int i=1;i<=n;i++){
        if(i>1) printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");
}