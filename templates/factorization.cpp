vector<int> Factorization(int n){
    vector<int> v;
    while(n % 2 == 0){
      v.pb(2);
      n /= 2;
    }
    for(int i = 3; i*i <= n; i += 2){
      while(n % i == 0){
        v.pb(i);
        n /= i;
      }
    }
    if(n > 1) v.pb(n);
    return v;
}