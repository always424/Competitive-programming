int par[MAXN],sz[MAXN];
        void make_set(int i){
            par[i]=i;
            sz[i]=1;
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
