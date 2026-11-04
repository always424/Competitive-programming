int dp[3005][3005],n,m;
string s,s1,ans;
int goriberdp(int i,int j){
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res;
    if(s[i]==s1[j]){
        res=1+goriberdp(i+1,j+1);
    }
    else{
        res=max({goriberdp(i,j+1),goriberdp(i+1,j)});
    }
    return dp[i][j]=res;
}
void recons(int i,int j){
    
    while(n>i && m>j){
        if(s[i]==s1[j]){
            ans+=s[i];
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]) i++;
        else j++;
    }
}

void solve(){
    cin>>s>>s1;
    n=s.size();
    m=s1.size();
    for(int i=0;i<=3001;i++){
        for(int j=0;j<=3001;j++) dp[i][j]=-1;
    }
    int res=goriberdp(0,0);
    recons(0,0);
    cout<<ans;
}
