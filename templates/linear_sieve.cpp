const int N = 1e5+1;
vector<int> lp(N+1);
vector<int> pr;

void preSolve(){
  for(int i = 2; i <= N; i++){
    if(lp[i] == 0){
      lp[i] = i;
      pr.pb(i);
    }
  }
  for(int j = 0; j < sz(pr) && pr[j] <= lp[i] && i*pr[j] <= N; j++){
    lp[i*pr[j]] = pr[j];
  }
}

vi Factorization(int n){
  vi ans;
  while(lp[n]){
    ans.pb(lp[n]);
    n /= lp[n];
  }
  return ans;
}