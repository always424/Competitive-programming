 int par[MAXN], sz[MAXN];
        void make_set(int i){
            par[i] =i;
            sz[i] = 1;
        }
        int find_set(int child){
            if(par[child] == child) return child;
            return par[child] = find_set(par[child]);
         }
         void union_set(int a,int b){
            int pa = find_set(a);
            int pb = find_set(b);
            if(pa==pb) return;
            if(sz[pa]<sz[pb]) swap(pa,pb);
            par[pb] = pa;
            sz[pa]+=sz[pb];

         }
       
        void always424(int tc) {
            int n,m; cin>>n>>m;
            vector<pair<int,pair<int,int>>>edges;
            for(int i =0;i<m;i++){
                int u,v,w; cin>>u>>v>>w;
                edges.push_back({w,{u,v}});
            }
            sort(all(edges));
            for(int i =1;i<=n;i++) make_set(i);
            ll ans =0;
            for(auto p : edges){
                if(find_set(p.second.first) != find_set(p.second.second)){
                    ans+=p.first;
                    union_set(p.second.first,p.second.second);
                }
            }
            cout<<ans;
        }
