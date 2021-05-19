#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

const int MX = 1e5+5;
int n,m;
vector<int> adj[MX];
bool vis[MX] = {false};
int team[MX] = {0};
bool possible = true;

void dfs(int node, int prev){
  vis[node] = true;
  if(team[prev]==1) team[node] = 2;
  else team[node] = 1;

  for(auto u: adj[node]){
    if(vis[u]){
      if(team[node]==team[u]) possible = false;
    }
    else{
      dfs(u, node);
    }
  }
}

int main(){
  cin>>n>>m; 
  for(int i=0; i<m; i++){
    int a,b; cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  team[0] = 0;
  for(int i=1; i<=n; i++){
    if(!vis[i]) dfs(i,0);
  }

  if(!possible) cout<<"IMPOSSIBLE";
  else{
    for(int i=1; i<=n; i++){
      cout<<team[i]<<" ";
    }
  } 
  
  return 0;
}
