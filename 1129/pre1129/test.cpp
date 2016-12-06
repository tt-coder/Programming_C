fact(n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

findMax(A,l,r){
    m = (l+r)/2;
    if(l== r -1 ){
        return A[l];
    }else{
        u = findMax(A,l,m);
        v = findMax(A,m,r);
        x = max(u,v);
        return x;
    }
}