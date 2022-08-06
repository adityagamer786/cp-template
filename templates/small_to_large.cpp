int a[N], b[N];
vi g[N];
set<int> vals[N];

void init(int v, int p){
  b[v] = a[v];
  if(p != -1) b[v] ^= b[p];
  each(u, g[v]) if(u != p) init(u,v);
}

int ans;

void calc(int v, int p){
  bool bad = false;
  vals[v].insert(b[v]);
  for (int u : g[v]) if (u != p) {
    calc(u, v);
    if (vals[v].size() < vals[u].size()) vals[v].swap(vals[u]);
    each(x, vals[u]) bad |= vals[v].count(x^a[v]);
    each(x, vals[u]) vals[v].insert(x);
    vals[u].clear();
  }
  if(bad){
    ans++;
    vals[v].clear();
  }
}
