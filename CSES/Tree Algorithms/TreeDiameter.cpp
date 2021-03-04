#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MX = 2e5+5;
int n;
vector<int> adj[MX];
int dist1[MX];
int dist2[MX];

// Function to find furthest node from result of dfs1
void dfs2(int node, int parent){
  dist2[node] = dist2[parent]+1;
  for(auto u: adj[node]){
    if(u!=parent){
      dfs2(u, node);
    }
  }
}

// Function to find furthest node from an arbitrary node a
void dfs1(int node, int parent){ 
  dist1[node] = dist1[parent]+1;
  for(auto u: adj[node]){
    if(u!=parent){
      dfs1(u, node);
    }
  }
}

int main() {
  cin>>n;
  for(int i=0; i<n-1; i++){
    int a,b; cin>>a>>b;
    adj[a].push_back(b), adj[b].push_back(a);
  }

  // Calculate furthest distance from arbitrary node a(in this case 1)
  dist1[0] = 0;
  dfs1(1,0);
  int maxNode = 1, maxDepth = 1;
  for(int i=1; i<=n; i++){
    if(maxDepth < dist1[i]){
      maxNode = i, maxDepth = dist1[i];
    }
  }

  //Calculte furthest distance from result of previous step(node b)
  dist2[0] = 0;
  dfs2(maxNode, 0);
  int diameter = 0;
  for(int i=1; i<=n; i++){
    diameter = max(diameter, dist2[i]);
  }

  cout<<diameter-1;
}
