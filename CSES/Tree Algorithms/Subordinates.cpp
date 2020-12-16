#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[200002];
int sub[200002]={0};

void dfs(int node, int prev){
  sub[prev]++;
  for(auto u: adj[node]){
    if(u!=prev){
      dfs(u, node);
      sub[node]+=sub[u];
    }
  }
}

int main() {
  cin>>n;
  for(int i=2; i<=n; i++){
    int x;
    cin>>x;
    adj[x].push_back(i);
  }
  dfs(1,0);
  for(int i=1; i<n; i++){
    cout<<sub[i]<<" ";
  }
  cout<<sub[n];
}
