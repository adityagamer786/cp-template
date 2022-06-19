struct SegmentTree {
  vector<int> t;
  int n;

  // this is the main function for merging nodes
  int combine(int a, int b){
    return a+b;
  }

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
      t[v] = combine(t[v*2],t[v*2+1]);
    }
  }

  int sumUtil(int v, int tl, int tr, int l, int r){
    if(l == tl && r == tr){
      return t[v];
    }
    int tm = (tl+tr)/2;

    bool c1 = true, c2 = true;
    if(l > min(r,tm)) c1 = false;
    if(max(l,tm+1) > r) c2 = false;
    if(c1 && c2){
      return combine(sumUtil(v*2, tl, tm, l, min(r,tm)),sumUtil(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
    if(c1) return sumUtil(v*2, tl, tm, l, min(r,tm));
    if(c2) return sumUtil(v*2+1, tm+1, tr, max(l, tm+1), r);
    return 0; // will never happen
  }

  int sum(int l, int r){
    if(l > r) return 0;
    return sumUtil(1,0,n-1,l,r);
  }

  void updateUtil(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
      t[v] = new_val;
    } else{
      int tm = (tl+tr)/2;
      if(pos <= tm) updateUtil(v*2, tl, tm, pos, new_val);
      else updateUtil(v*2+1, tm+1, tr, pos, new_val);
      t[v] = combine(t[v*2], t[v*2+1]);
    }
  }

  void update(int pos, int val){
    updateUtil(1,0,n-1, pos, val);
  }
};
