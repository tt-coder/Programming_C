solve(i,m){
    if(dp[i][m] == true){
        return dp[i][m];
    }
    if(m==0){
        dp[i][m] = true;
    }else if(i>=n){
        dp[i][m] = false;
    }else if(solve(i+1,m)){
        dp[i][m] = true;
    }else if(solve(i+1,m-A[i])){
        dp[i][m] = true;
    }else{
        dp[i][m] = false;
    }
    return dp[i][m];
}