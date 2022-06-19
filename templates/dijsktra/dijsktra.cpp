struct edge{
  int to, cost;
};

vector<int> dijsktra(int s, vector<vector<edge>> &G){
  vi dist(sz(G), inf);
  dist[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0ll, s});

  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    int d = cur.fi, v = cur.se;
    if(dist[v] != d) continue; 
    for(auto e: G[v]){
      int vv = e.to, c = e.cost;
      if(dist[vv] > dist[v]+c){
        dist[vv] = dist[v]+c; 
        pq.push({dist[vv], vv});
      }
    }
  }
  return dist;
}

void solve(){
  // no proof = no submission
  int k,i, j, q, x, y;
  cin >> n >> m;
  vector<vector<edge>> G(n);
  forn(i,m){
    int a,b,c; 
    cin >> a >> b >> c; 
    G[a-1].pb({b-1,c});
    G[b-1].pb({a-1,c});
  }
  vi idx = dijsktra(0,G);
  for(i = 1; i < n; i++) cout << idx[i]+1 << " " ;
}