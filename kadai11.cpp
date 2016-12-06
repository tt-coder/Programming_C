#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 10000000

int n;
int a[MAX];

int getMax(int *a, int p, int q){
    int mid = (p + q) / 2;
    if(p == q - 1 ){
        printf("%d\n",a[p]);
        return a[p];
    }else{
        int x = getMax(a,p,mid);
        int y = getMax(a,mid,q);
        int z = max(x,y);
        printf("%d\n",z);
        return z;
    }
}

int main(){
    int max;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max = getMax(a,0,n);
    return 0;
}