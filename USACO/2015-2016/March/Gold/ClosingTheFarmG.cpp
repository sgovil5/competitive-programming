#include <iostream>
#include <vector>
using namespace std;

void setIO(string fileName = "") {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

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

const int MX = 200010;
int n,m, cmps = 0;
int closeOrder[MX], closePlace[MX], u[MX], v[MX];
bool res[MX];
vector<int> adj[MX];
DSU d;

int main(){
    setIO("closing");
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u[i]>>v[i];
    }
    for(int i=0; i<n; i++){
        cin>>closeOrder[i];
        closePlace[closeOrder[i]] = i;
    }
    d.init(n+1);

    for(int i=0; i<m; i++){
        if(closePlace[u[i]]>closePlace[v[i]]) adj[v[i]].push_back(u[i]);
        else adj[u[i]].push_back(v[i]);
    }

    for(int i=n-1; i>=0; i--){
        int u = closeOrder[i]; cmps++;
        for(auto v: adj[u]){
            if(!d.sameSet(u,v)){
                d.unite(u,v); cmps--;
            }
        }
        res[i] = (cmps<=1);
    }

    for(int i=0; i<n; i++) cout<<(res[i] ? "YES" : "NO")<<endl;
}