#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int n, m, cnt=0;
vector<int> cats(MAXN);
vector<bool> visited(MAXN, false);
vector<vector<int>> adj(MAXN);

void dfs(int node, int currCats) {
    visited[node] = true;

    if(cats[node]==1) ++currCats;
    else if(cats[node]==0) currCats = 0;

    // cout<<node<<" "<<currCats<<endl;

    if(currCats>m) return;

    if(node!=1 && adj[node].size()==1) cnt++;

    for (auto child: adj[node]) {
        if(!visited[child]) {
            dfs(child, currCats);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin>>cats[i];
    }
    for(int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    cout<<cnt;
}