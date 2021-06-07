#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define f first
#define s second

void setIO(string fileName = "") {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

struct DSU {
	vector<int> e;
	void init(int N) { e = vector<int>(N, -1); }

	// get representative component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	
	bool same_set(int a, int b) { return get(a) == get(b); }
	
	int size(int x) { return -e[get(x)]; }
	
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};

struct Edge{
    int a,b,w;
};

bool cmp(const Edge& a, const Edge& b){return a.w<b.w;}

int n;
vector<pair<int,int>> points;
vector<Edge> edges;
DSU d;

int main(){
    setIO("moocast");
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        points.push_back({x,y});
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int dist = pow(points[i].f-points[j].f, 2) + pow(points[i].s-points[j].s, 2);
            edges.push_back({i,j,dist});
        }
    }

    d.init(n);

    sort(begin(edges), end(edges), cmp);

    int lastW, numCmp = n;
    for(Edge curr: edges){
        if(!d.same_set(curr.a, curr.b)){
            d.unite(curr.a, curr.b);
            lastW = curr.w;
            if(--numCmp==1) break;
        }
    }   

    cout<<lastW<<endl;
}