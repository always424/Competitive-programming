ll v[N],t[4*N];
void build(int n,int l,int r){
    if(l==r){
        t[n]=v[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*n,l,mid);
    build(2*n+1,mid+1,r);
    t[n]=t[2*n]+t[2*n+1];
}
void update(int n,int l , int r, ll idx, ll val){
    if(idx<l || idx>r) return;
    if(l==r ){
        // v[idx]=val;
        t[n]=val;
        return;
    }
    int mid=(l+r)/2;
    update(2*n,l,mid,idx,val);
    update(2*n+1,mid+1,r,idx,val);
    t[n]=t[2*n]+t[2*n+1];
}
ll query(int n,int s, int e,int l, int r){
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return t[n];
    int mid=(s+e)/2;
    return query(2*n,s,mid,l,r)+query(2*n+1,mid+1,e,l,r);
}
