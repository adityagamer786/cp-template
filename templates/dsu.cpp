class dsu {
private:
  vector<int> v, siz;
public:
  dsu(int);
  int find(int);
  void merge(int,int);
  int size(int x){return siz[find(x)];}
  bool is_connected(int x, int y){return find(x) == find(y);}
};

dsu::dsu(int n) : v(n), siz(n, 1) {
    for(int i = 0; i < n; i++){
      v[i] = i;
    }
}

int dsu::find(int x){
  int r = x;
  while(v[r] != r)
    r = v[r];

  while(v[x] != r){
    int t = v[x];
    v[x] = r;
    x = t;
  }
  return r;
}

void dsu::merge(int i, int j){
  int a = find(i), b = find(j);
  if(a == b)
    return;

  if(siz[b] < siz[a]){
    v[b] = a;
    siz[a] += siz[b];
  } else{
    v[a] = b;
    siz[b] += siz[a];
  }
}
