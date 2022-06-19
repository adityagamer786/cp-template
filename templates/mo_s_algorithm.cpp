vi a; // make a global
int block_size = 400;
void remove(int idx);
void add(int idx);
int get_answer();
struct Query{
  int l, r, idx;
  bool operator<(Query other) const {
    return make_pair(l/block_size, r) < make_pair(other.l/block_size, other.r);
  }
};

int SUM;
void add(int idx){
  SUM += a[idx];
}
void remove(int idx){
  SUM -= a[idx];
}
int get_answer(){
  return SUM;
}

vi mo_s_algorithm(vector<Query> queries){ // not by reference due to sorting
  vi ans(sz(queries));
  sort(all(queries));

  // DS initialize
  SUM = 0;

  int cur_l = 0, cur_r = -1;
  for(Query q: queries){
    while(cur_l > q.l){
      cur_l--;
      add(cur_l);
    }
    while(cur_r < q.r){
      cur_r++;
      add(cur_r);
    }
    while(cur_l < q.l){
      remove(cur_l);
      cur_l++;
    }
    while(cur_r > q.r){
      remove(cur_r);
      cur_r--;
    }
    ans[q.idx] = get_answer();
  }
  return ans;
}

void solve(){
  int k,i, j, q, x, y;
  cin >> n >> q;
//   block_size = ceil(sqrt(n));
  dbg(block_size);
  a.resize(n);
  cin >> a;
  dbg(a);
  vector<Query> queries(q);
  forn(i,q){
    cin >> x >> y;
    x--; y--;
    queries[i].l = x; queries[i].r = y, queries[i].idx = i;
  }
  print(mo_s_algorithm(queries));
}
