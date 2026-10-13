const int N=500005;
vector<int>adj[N],par(N);
int up[N][20];
void dfs(int u,int p){
    up[u][0]=p;
    for(int i=1;i<20;i++){
        if(up[u][i-1]!=-1){
            up[u][i]=up[up[u][i-1]][i-1];
        }
        else up[u][i]=-1;
    }
    for(auto v:adj[u]){
        if(v!=p) dfs(v,u);
    }
}
int kancestor(int u,int k){
    for(int i=0;i<20;i++){
        if((k>>i) & 1){
            u=up[u][i];
            if(u==-1) break;
        }
    }
    return u;
}
