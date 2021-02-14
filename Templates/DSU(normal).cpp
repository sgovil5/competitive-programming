int par[max_v], sz[max_v]:
int find(x){
  if(x != par[x]) par[x] = find(par[x]);
  return par[x];
}
void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  if(sz[a] < sz[b]) swap(a, b);  
  par[b] = a;
  sz[a] += sz[b]
}
void make_dsu(){
  for(int i = 0; i<=n; i++){
    par[i] = i;
    sz[i] = 1;
  }
}
