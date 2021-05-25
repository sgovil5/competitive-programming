#include <iostream>
#include <vector>
#include <algorithm>
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

int n, m;
DSU d;
int main(){
  cin>>n>>m;
  d.init(n);
  int numCmp = n, mxSz = 1;
  for(int i=0; i<m; i++){
    int a,b; cin>>a>>b;
    a--,b--;
    if(!d.sameSet(a,b)) numCmp--;
    d.unite(a,b);
    mxSz = max(mxSz, d.size(a));
    cout<<numCmp<<' '<<mxSz<<endl;
  }
}