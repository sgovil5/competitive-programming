#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
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

const int MX = 200005;
int n,m;
// closePos[i] represents which position it closed at
// For example, if closePos[3] = 2, then farm 3 was the 3rd(0-index) farm to be closed 
int closeOrder[MX], closePos[MX], u[MX], v[MX];
bool res[MX];
DSU d;
vector<int> adj[MX];

int main(){
    setIO("closing");
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u[i]>>v[i];
    }
    for(int i=0; i<n; i++){
        cin>>closeOrder[i];
        closePos[closeOrder[i]] = i;
    }

    d.init(n+1);

    for(int i=0; i<m; i++){
        // If u[i] closes after v[i] then there will not be a connection between u[i] and v[i] once v[i] closes
        // Thus, we add only to the adj of v[i] because this connection will be irrelevant after
        if(closePos[u[i]]>closePos[v[i]]) adj[v[i]].push_back(u[i]);
        else adj[u[i]].push_back(v[i]);
    }

    int currComponents = 0;
    // We want to go backwards in terms of when the farm closes
    // This ensures that we can add "connected components" using DSU 
    // Deleting components is hard with DSU
    for(int i=n-1; i>=0; i--){
        int currNode = closeOrder[i];
        currComponents++;
        for(auto a: adj[currNode]){
            if(!d.sameSet(currNode, a)){
                // For each new farm we can connect with, we have 1 less component
                d.unite(a, currNode); currComponents--;
            }
        }
        // Make sure everything can fit into 1 component(group)
        res[i] = (currComponents<=1);
    }
    for(int i=0; i<n; i++)cout<<(res[i] ? "YES" : "NO")<<endl;
}