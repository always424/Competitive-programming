vector<ll>v(N),t(N);
void init(int n,int b,int e){
    if(b==e){
        t[n]=v[b];
        return;
    }
    int l=2*n;
    int r=2*n+1;
    int mid=(b+e)/2;
    init(l,b,mid);
    init(r,mid+1,e);
    t[n]=t[l]+t[r];
}
ll query(int n,int b,int e,int i, int j){
    if(e<i || b>j) return 0;
    if(i<=b && e<=j) return t[n];
    int l=2*n;
    int r=2*n+1;
    int mid=(b+e)/2;
    ll q1 = query(l,b,mid, i, j);
    ll q2 = query(r,mid+1,e, i, j);
    return q1+q2;
}
void update(int n,int b,int e,int idx, int val){
    if(e<idx || b>idx) return;
    if(b==e){
        t[n]=val;
        return;
    }
    int l=2*n;
    int r=2*n+1;
    int mid=(b+e)/2;
    update(l,b,mid,idx,val);
    update(r,mid+1,e,idx,val);
    t[n]=t[l]+t[r];
}
