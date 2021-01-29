#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[10002];
bool visited[100002]={false};

void dfs(int node){
  visited[node] = true;
  for(auto u: adj[node]){
    if(!visited[u]) dfs(u);
  }
}

int main() {
  cin>>n;
  for(int i=1; i<=n; i++){
    int x;
    cin>>x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  int ctr = 0;
  for(int i=1; i<=n; i++){
    if(!visited[i]){
      ctr++;
      dfs(i);
    }
  }
  cout<<ctr;
}
