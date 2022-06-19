vector<int> Divisors(int n){
    vector<int> v;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            v.pb(i);
            if((n/i) != i) v.pb(n/i);
        }
    }
    if(sz(v) == 0) v.pb(1); // needed when n = 0, remove if not needed
    return v;
}