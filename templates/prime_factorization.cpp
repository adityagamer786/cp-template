map<int,int> PrimeFactorization(int n){
  int i = 2;
  map<int,int> freq;
  while(i*i <= n){
    while(n%i == 0){
      freq[i]++;
      n /= i;
    }
    i++;
  }
  if(n >= 2) freq[n]++;
  return freq;
}