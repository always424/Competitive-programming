while(hi-lo >0.0000001){
        double mid=(lo+hi)/2;
        if(isok(mid)) hi=mid;
        else lo =mid;
}
