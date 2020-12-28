#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100004];
bool visited[100004]={false};
int team[100004]={0};
bool isPossible = true;

void dfs(int node, int prev){
  if(prev==1) team[node] = 2;
  else team[node] = 1;
  visited[node] = true;
  for(auto u: adj[node]){
    if(!visited[u]) dfs(u, team[node]);
    else if(visited[u]){
      if(team[node]==prev) isPossible = false;
    }
  }
}

int main() {
  cin>>n>>m;
  for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1; i<=n; i++){
    if(!visited[i]) dfs(i,1);
  }
  if(isPossible){
    for(int i=1; i<=n; i++){
      cout<<team[i]<<" ";
    }
  }
  else cout<<"IMPOSSIBLE"<<endl;
}
