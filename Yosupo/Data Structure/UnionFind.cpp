#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+5;
int n,q;
int sz[MXN], link[MXN];

struct DSU{
  void init(int sz[], int link[]){
    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
  }
  int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void unite(int a, int b, int sz[], int link[]) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
  }
};

int main() {
  cin>>n>>q;
  DSU dsu;
  dsu.init(sz, link);
  for(int i=0; i<q; i++){
    int t, u,v;
    cin>>t>>u>>v;
    if(t==0){
      dsu.unite(u, v, sz, link);
    }
    else{
      cout<<(dsu.same(u, v) ? 1 : 0)<<endl;
    }
  }
}
