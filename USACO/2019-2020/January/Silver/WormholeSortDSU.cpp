#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define f first
#define s second

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}
 
struct DSU {
	vector<int> e;
	void init(int N) { e = vector<int>(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

bool cmp(const pair<pair<int,int>, int>& a, const pair<pair<int,int>,int>& b) {return a.s>b.s;}

int n,m;
vector<int> order;
vector<pair<pair<int,int>, int>> holes;
DSU d;

int main(){
    setIO("wormsort");
    cin>>n>>m;
    order = vector<int>(n+1);
    for(int i=1; i<=n; i++) cin>>order[i];

    for(int i=0; i<m; i++){
        int a,b,w; cin>>a>>b>>w;
        holes.push_back({{a,b},w});
    }
    sort(begin(holes), end(holes), cmp);

    d.init(n+1);
    int indx = -1;

    for(int i=1; i<=n; i++){
        while(!d.same_set(i, order[i])){
            indx++;
            d.unite(holes[indx].f.f, holes[indx].f.s);
        }
    }

    if(indx == -1) cout<<"-1";
    else cout<<holes[indx].s<<endl;
}