vector<int>adj[N],par(N),vis(N),curstack(N);
int cy,cys,cye;
void dfs(int u,int p){
    vis[u]=1;
    par[u]=p;
    curstack[u]=1;
    for(auto v:adj[u]){
        if(vis[v]){
            if(curstack[v]){
                cy=1;
                cys=v;
                cye=u;
                continue;
            }
            continue;
        }
        dfs(v,u);
    }
    curstack[u]=0;
}
void solve(int tc){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }                 
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,0);
        if(cy) break;
    }
    if(cy){
        vector<int>ans;
        while(cye!=cys){
            ans.push_back(cye);
            cye=par[cye];
        }
        ans.push_back(cye);
        reverse(ans.begin(),ans.end());
        ans.push_back(cye);
        cout<<ans.size()<<'\n';
        for(auto u:ans) cout<<u<<' ';
    }
    else cout<<"IMPOSSIBLE";
}
