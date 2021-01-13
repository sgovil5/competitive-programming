#include <bits/stdc++.h>
#define int long long // Uhh this isn't neccessary 
using namespace std;

int n;
vector<int> adj[100002];
bool visited[100002]={false};
int days = 0;

void dfs(int node){
  visited[node] = true;
  int children = 0;
  // Count all the children of the current node excluding previous ones
  for(int u : adj[node]) if(!visited[u]) ++children;
  // Solve how many days it takes to get the necessary cows to move forward
  int cows = 1;
  while(cows <= children) cows *= 2, ++days;
  for(auto u: adj[node]){
    // Make sure we haven't been to the node before
    if(!visited[u]){
      // Make sure that the node we are going to is not a leaf
      if(adj[u].size()>=2) dfs(u);
      // Increment days anyways if the previous if condition is met
      days++;
    }
  }
}
// Why am I using a signed in smh lmao
signed main(){
  cin>>n;
  for(int i=0; i<n-1; i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  cout<<days;
}
