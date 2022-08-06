auto cpow = [&] (int n, int p){
  int ans = 1;
  for(int i = 1; i <= p; i++){
    ans *= n;
  }
  return ans;
};