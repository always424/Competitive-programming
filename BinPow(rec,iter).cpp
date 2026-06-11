ll binpowRec(ll a,ll b){
    a%=mod;
    if(b==0) return 1;
    ll res = binpowRec(a,b/2);
    if(b&1) return (a*((res*1LL*res)%mod))%mod;
    else return (res*1LL*res)%mod;
}

ll binpowIter(ll a,ll b){
    ll ans =1;
    while(b){
        if(b&1){
            ans = (ans*1LL*a)%mod;
        }
        a=(a*1LL*a)%mod;
        b>>=1;
    }
    return ans%mod;
}
