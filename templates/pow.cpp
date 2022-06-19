auto cpow = [&] (int n, int p){
  int ans = 1;
  for(i = 1; i <= p; i++){
    ans *= n;
  }
  return ans;
};