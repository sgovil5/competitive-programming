#include <iostream>
#include <vector>
using namespace std;

const int MX = 2e5+10;
int t, n, m;
vector<vector<int>> adj;
vector<int> c1, c2;
int color[MX] = {0};
bool vis[MX];

void dfs(int node, int prev){
    vis[node] = true;
    if(color[prev]==1){color[node]=2; c2.push_back(node);}
    else {color[node]=1; c1.push_back(node);}
    
    for(auto u: adj[node]){
        if(!vis[u]){
            dfs(u, node);
        }
    }
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        adj = vector<vector<int>>(n+1);
        c1.clear(); c2.clear();
        fill(begin(color), color+n+2, 0); fill(begin(vis), vis+n+2, false);

        for(int i=0; i<m; i++){
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        color[0] = 2;
        dfs(1, 0);

        if(c1.size()<=c2.size()){
            cout<<c1.size()<<endl;
            for(auto elem: c1) cout<<elem<<" ";
        }
        else{
            cout<<c2.size()<<endl;
            for(auto elem: c2) cout<<elem<<" ";
        }
        cout<<endl;
    }
    return 0;
}