#include <cstdio>

int n,a[100];

int makeM(int i, int m){
    if(m == 0){
        return 1;
    }
    if(n <= i){
        return 0;
    }
    return makeM(i+1, m) || makeM(i+1, m - a[i]);
}

int main(){
    int q,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&m);
        if(makeM(0,m) == 1){
            printf("true\n");
        }else{
            printf("false\n");
        }
    }
    return 0;
}