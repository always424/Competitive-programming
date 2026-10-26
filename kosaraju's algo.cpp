vector<int>adj[N],readj[N],vis(N);
stack<int>st;
vector<int>scc;
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]) dfs(v);
    }
    st.push(u);
}
void dfs1(int u){
    vis[u]=1;
    scc.push_back(u);
    for(auto v:readj[u]){
        if(!vis[v]) dfs1(v);
    }
}
void solve(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        readj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    for(int i=1;i<=n;i++) vis[i]=0;
    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(!vis[u]){
            scc.clear();
            dfs1(u);
            for(auto x:scc) cout<<x<<' ';
            cout<<'\n';
        }
    }
}
