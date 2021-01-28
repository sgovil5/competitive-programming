#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5+1;
int n,m;
vector<int> adj[MXN];
bool visited[MXN] = {false};
int rep[MXN];

void dfs(int node){
  visited[node] = true;
  for(int u: adj[node]){
    if(!visited[u]){
      dfs(u);
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
  int count = 0;
  for(int i=1; i<=n; i++){
    if(!visited[i]){
      rep[count++]=i;
      dfs(i);
    }
  }
  cout<<count-1<<endl;
  for(int i=1; i<count; i++){
    cout<<rep[i-1]<<" "<<rep[i]<<endl;
  }
}
