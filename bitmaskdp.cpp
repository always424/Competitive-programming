const int mx=(1<<16)+123;
int dp[20][mx],v[20][20],n;
int fokirerdp(int i,int mask){
    if(i==n) return 0;
    if((1<<n)-1 == mask) return 0;
    if(dp[i][mask] !=-1 ) return dp[i][mask];
    int res=0;
    for(int j=0;j<n;j++){
        if(((1 << j) & mask) ==0){
            res = max(res,v[i][j]+fokirerdp(i+1,((1<<j) | mask)));
        }
    }
    return dp[i][mask] =res;
}
