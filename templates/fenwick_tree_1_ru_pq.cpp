struct FenwickTreeOneBasedIndexing {
  vector<int> bit; // binary indexed tree
  int n;

  FenwickTreeOneBasedIndexing(int n){
    this->n = n+1;
    bit.assign(n+1, 0);
  }

  FenwickTreeOneBasedIndexing(vector<int> a) : FenwickTreeOneBasedIndexing(a.size()){
    for(size_t i = 0; i < a.size(); i++){
      range_add(i, i, a[i]);
    }
  }

  void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
  }
  
  void range_add(int l, int r, int val) {
    if(l > r){
      cerr << l <<  " < " << r << "\n";
      return;
    }
    add(l, val);
    add(r + 1, -val);
  }

  int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
  }
};