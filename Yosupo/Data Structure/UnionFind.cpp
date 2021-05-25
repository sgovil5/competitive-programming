#include <iostream>
#include <vector>
using namespace std;

struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	// get representive component, uses path compression
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

DSU dsu;
int n,q;
int main(){
  cin>>n>>q;
  dsu.init(n);
  for(int i=0; i<q; i++){
    int x,u,v; cin>>x>>u>>v;
    if(x==0){
      dsu.unite(u,v);
    }
    else{
      if(dsu.sameSet(u,v)) cout<<1<<endl;
      else cout<<0<<endl;
    }
  }
}