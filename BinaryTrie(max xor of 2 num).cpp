int tr[30*N][2],cnt[N*30],node=1;
void insert(int x){
    int u=1;
    for(int i=30;i>=0;i--){
        int bit=(x>>i)&1;
        if(!tr[u][bit]){
            node++;
            tr[u][bit]=node;
        }
        u=tr[u][bit];
        cnt[u]++;
    }
}
void del(int x){
    int u=1;
    for(int i=30;i>=0;i--){
        int bit=(x>>i)&1;
        u=tr[u][bit];
        cnt[u]--;
    }
}
int mx(int x){
    int u=1;
    int ans=0;
    for(int i=30;i>=0;i--){
        int bit=(x>>i)&1;
        int best=1-bit;
        if(tr[u][best] && cnt[tr[u][best]]>0){
            ans|=(1<<i);
            u=tr[u][best];
        }
        else u=tr[u][bit]; 
    }
    return ans;
}
void solve(){
    int n; cin>>n;
    insert(0);
    while(n--){
        char q; cin>>q;
        int x; cin>>x;
        if(q=='+'){
            insert(x);
        }
        else if(q=='-'){
            del(x);
        }
        else cout<<mx(x)<<'\n';
    }

}
