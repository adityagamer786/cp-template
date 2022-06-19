struct SegmentTree {

  // LAZY Segment Tree

  vector<int> t;
  int n;

  // this is the main function for merging nodes
  // this doesnt work
  // int combine(int a, int b){
  //   return a+b;
  // }

  SegmentTree(int n){
    this->n = n;
    t.assign(4*n+1, 0);
  }

  SegmentTree(vector<int> a) : SegmentTree(a.size()){
    build(a, 1, 0, sz(a)-1);
  }

  void build(vi &a, int v, int tl, int tr){
    if(tl == tr){
      t[v] = a[tl];
    } else{
      int tm = (tl+tr)/2;
      build(a, v*2, tl, tm);
      build(a, v*2+1, tm+1, tr);
      t[v] = 0;
    }
  }

  void updateUtil(int v, int tl, int tr, int l, int r, int add){
    if(l > r){
      return;
    }
    if(l == tl && r == tr){
      t[v] += add;
    } else{
      int tm = (tl+tr)/2;
      updateUtil(v*2, tl, tm, l, min(r, tm), add);
      updateUtil(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
  }

  void update(int l, int r, int add){
    updateUtil(1, 0, n-1, l, r, add);
  }

  int getUtil(int v, int tl, int tr, int pos){
    if(tl == tr) return t[v];
    int tm = (tl+tr)/2;
    if(pos <= tm) return t[v] + getUtil(v*2, tl, tm, pos);
    else return t[v] + getUtil(v*2+1, tm+1, tr, pos);
  }

  int get(int pos){
    return getUtil(1, 0, n-1, pos);
  }
};