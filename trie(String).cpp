int tr[N][26],endw[N],pref_cnt[N],node_cnt=1;
void insert(string &s){
    int u=1;
    for(auto ch:s){
        int c=ch-'a';
        if(!tr[u][c]){
            node_cnt++;
            tr[u][c]=node_cnt;
        }
        u=tr[u][c];
        pref_cnt[u]++;
    }
    endw[u]++;
}
int check(string &s){
    int u=1;
    for(auto ch:s){
        int c=ch-'a';
        if(!tr[u][c]) return 0;
        u=tr[u][c];
    }
    return endw[u];
}
void del(string &s){
    if(!check(s)) return;
    int u=1;
    for(auto ch:s){
        int c=ch-'a';
        if(!tr[u][c]) return;
        u=tr[u][c];
        pref_cnt[u]--;
    }
    endw[u]--;
}
int prefix(string &s){
    int u=1;
    for(auto ch:s){
        int c=ch-'a';
        if(!tr[u][c]) return 0;
        u=tr[u][c];
    }
    return pref_cnt[u];
}
void solve(){
    int n,m; cin>>n;
    while(n--){
        string q; cin>>q;
        string s; cin>>s;
        if(q=="insert"){
            insert(s);
        }
        else if(q=="del"){
            del(s);
        }
        else if(q=="prefix"){
            cout<<prefix(s)<<'\n';
        }
        else{
            if(check(s)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
