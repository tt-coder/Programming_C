#include <cstdio>

int n,a[100];

int solve(int i, int m){
    if(m == 0){
        return 1;
    }
    if(n <= i){
        return 0;
    }
    return solve(i+1, m) || solve(i+1, m - a[i]);
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
        if(solve(0,m) == 1){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}