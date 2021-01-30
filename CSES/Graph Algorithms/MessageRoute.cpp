#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  // Required data structs
  const int MXN = 1e5+1;
  vector<int> adj[MXN];
  bool vis[MXN] = {false};
  int parent[MXN];
  queue<int> q;
  //Input
  for(int i=0; i<m; i++){
    int a,b; cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  //Start BFS
  parent[1] = -1;
  vis[1] = true;
  q.push(1);
  while(!q.empty()){
    int currNode = q.front();
    q.pop();
    for(auto u: adj[currNode]){
      if(!vis[u]){
        vis[u] = true;
        parent[u] = currNode;
        q.push(u);
      }
    }
  }
  if(!vis[n]) cout<<"IMPOSSIBLE";
  else{
    // Set up dist calculation
    int dist = 1;
    int currPar = parent[n];
    vector<int> path;
    path.push_back(n);
    // Calculate dist and trace path back
    while(currPar!=-1){
      path.push_back(currPar);
      currPar = parent[currPar];
      dist++;
    }
    // Output!
    cout<<dist<<endl;
    for(int i=dist-1; i>=0; i--){
      cout<<path[i]<<" ";
    }
  }
}
