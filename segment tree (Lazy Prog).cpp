vector<ll>v(N),tree_sum(N*4),tree_prop(N*4);
void init(int n,int b ,int e){
    if(e==b){
        tree_sum[n]=v[e];
        return;
    }
    int l=2*n;
    int r=2*n+1;
    int mid=(e+b)/2;
    init(l,b,mid);
    init(r,mid+1,e);
    tree_sum[n]=tree_sum[l]+tree_sum[r];
}
ll query(int n,int b,int e,int i,int j,ll carry=0){
    if(e<i || j<b) return 0;
    if(i<=b && e<=j){
        return tree_sum[n]+(e-b+1)*carry;
    }
    int l=2*n;
    int r=2*n+1;
    int mid=(b+e)/2;
    int q1 = query(l,b,mid, i, j,carry+tree_prop[n]);
    int q2 = query(r,mid+1,e, i, j,carry+tree_prop[n]);
    
    return q1+q2;
}
void update(int n,int b,int e, int i,int j,ll x){
    if(e<i || j<b) return;
    if(i<=b && e<=j){
        tree_sum[n]+=(e-b+1)*x;
        tree_prop[n]+=x;
        return;
    }
    int l=2*n;
    int r=2*n+1;
    int mid=(b+e)/2;
    update(l,b,mid,i,j,x);
    update(r,mid+1,e,i,j,x);
    tree_sum[n]=tree_sum[l]+tree_sum[r]+(e-b+1)*tree_prop[n];
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
    }
    init(1, 1, 7);
    update(1, 1, 7, 1, 7, 2);
    update(1, 1, 7, 1, 4, 3);
    cout<<query(n, 1, n, 1, 5);
}
