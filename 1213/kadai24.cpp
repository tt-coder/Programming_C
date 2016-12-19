#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 10000000

int n;
int a[MAX];

int getMin(int *a, int p, int q){
    int mid = (p + q) / 2;
    if(p == q - 1 ){
        printf("%d\n",a[p]);
        return a[p];
    }else{
        int x = getMin(a,p,mid);
        int y = getMin(a,mid,q);
        int z = min(x,y);
        printf("%d\n",z);
        return z;
    }
}

int main(){
    int min;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    min = getMin(a,0,n);
    return 0;
}