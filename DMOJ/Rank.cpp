#include <iostream>
#include <vector>
using namespace std;

const int MX = 21;

int n,k, ans = 0;
vector<int> adj[MX];
bool cyclic[MX] = {false};
bool vis[MX] = {false};

void dfs(int curr){
    if(vis[curr]) return;
    vis[curr] = true;
    for(auto u: adj[curr]){
        if(vis[u]){
            cyclic[u] = true;
        } else{
            dfs(u);
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=0; i<k; i++){
        int a, b, sa, sb; cin>>a>>b>>sa>>sb;
        if(sb>sa) swap(a,b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<MX; j++) vis[j] = false;
        dfs(i);
        if(cyclic[i]) ans++;
    }
    cout<<ans<<endl;
}