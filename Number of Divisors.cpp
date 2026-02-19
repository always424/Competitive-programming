    ll n; cin>>n;
    ll ans=1;
    for(int i =0;prime[i]*prime[i] <=n;i++){
        if(n%prime[i]==0){
            int x=1;
            while(n%prime[i]==0){
                n/=prime[i];
                x++;
            }
            ans*=x;
        }
    }
    if(n!=1) ans*=2;
    cout<<ans<<"\n";
