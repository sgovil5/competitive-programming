#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int n, m;
bool adj[105][105]; //since # nodes is small, you can use an adjacency matrix to easily delete edges
bool vis[105];

void dfs(int v) {
    vis[v] = true;
    for (int to = 0; to < n; to++) {
        if (adj[v][to] && !vis[to]) {
            dfs(to);
        }
    }
}

void solve() {
    memset(adj, false, sizeof(adj));
    vector<pi> edges;
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
        edges.pb(mp(u, v));
    }
    for (pi x : edges) {
        adj[x.f][x.s] = false;
        adj[x.s][x.f] = false;
        memset(vis, false, sizeof(vis));
        dfs(0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cout << "Yes" << '\n';
                return;
            }
        }
        adj[x.f][x.s] = true;
        adj[x.s][x.f] = true;
    }
    cout << "No" << '\n';
}

int main() {
    setIO();
    while (cin >> n >> m && (n || m)) {
        solve(); 
    }
}
