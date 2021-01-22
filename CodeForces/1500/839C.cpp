/* 
Find number of leafs and then find the probability of being reached and distance from root
Output the sum of all distances from root time probability for each leaf
Thank you to izhang for pointing out error in my solution
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MXN = 1e5 + 1;
int n;
vector<int> adj[MXN];
bool vis[MXN]={false};
ll ancestors[MXN]={0};
ld prob[MXN];
vector<pair<ll,ld>> leafs; // Number of ancestors, probability of getting there

void dfs(int node, int prev){
  if(vis[node]) return;
  vis[node] = true;
  //Basically dp?
  if(adj[prev].size()-1==0){
    prob[node] = prob[prev];
  }
  else{
    prob[node] = prob[prev] / (adj[prev].size()-1);
  }
  ancestors[node] = ancestors[prev]+1;
  //Check if node is leaf
  if(adj[node].size()==1 && vis[prev]){
    leafs.push_back({ancestors[node], prob[node]});
  }
  else{
    for(auto u: adj[node]){
      if(!vis[u]) dfs(u,node);
    }
  }
}

int main(){
  cin>>n;
  for(int i=0; i<n-1; i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  // Done to make dfs probability calculation easier
  adj[1].push_back(0);
  // Setting a base
  ancestors[1] = 0;
  prob[1] = 1;
  vis[1] = true;
  for(auto u: adj[1]){
    dfs(u,1);
  } 
  ld ans = 0;
  // Multiply probability by distance from root
  for(int i=0; i<leafs.size(); i++){
    ans += leafs[i].first * leafs[i].second;
  }
  // I hate doubles lmao
  cout<<setprecision(7)<<ans;
  return 0;
}
