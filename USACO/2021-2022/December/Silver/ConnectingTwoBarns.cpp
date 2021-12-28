#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5+5;
vector<int> adj[MX];
int comps[MX]={-1};

int closest (long long node, set<long long>& x) {
  auto it = x.lower_bound(node);
  if (it == x.end()) return *--it;
  else if (it == x.begin()) return *it;
  else {
    long long above = *it;
    long long below = *--it;
    if (abs(node - above) < abs(node - below)) return above;
    else return below;
  }
}

void dfs(int node, int cmpNum){
  comps[node] = cmpNum;

  for(auto u: adj[node]){
    if(comps[u]==-1) dfs(u, cmpNum);
  }
}

void solve(){
  int n, m; cin>>n>>m;
  
  fill(comps, comps+MX, -1);
  for(int i=0; i<MX; i++){
    adj[i].clear();
  }

  for(int i=0; i<m; i++){
    int a,b; cin>>a>>b; a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  //calculate components
  int currCmp = 0;
  for(int i=0; i<n; i++){
    if(comps[i]==-1) dfs(i, ++currCmp);
  }

  // compute components of 1 and n 
  int nNum = comps[n-1];
  int fNum = comps[0];

  // incase 1 and n are in the same comp
  if(fNum==nNum){
    cout<<0<<endl;
    return;
  }
  
  // create list of components
  set<long long> compList[currCmp+1];
  for(int i=0; i<n; i++){
    compList[comps[i]].insert(i);
  }

  long long ans = 1e18+5;

  //find the best connection if you make 1 connection from comp 1 to comp n
  for(auto elem: compList[fNum]){
    long long connectToN = closest(elem, compList[nNum]);
    ans = min(ans, (long long) (elem-connectToN) * (elem-connectToN));
  }

  // find the best connections for each comp assuming you make 2 connections
  for(int i=2; i<currCmp; i++){
    // find the minimum distance from comp 1 to comp i
    long long minDist1 = 1e18+5;
    for(auto elem: compList[i]){
      long long connectTo1 = closest(elem, compList[fNum]);
      minDist1 = min(minDist1, (long long) (elem-connectTo1) * (elem-connectTo1));
    }

    // find minimum distance from comp i to comp N
    long long minDistN = 1e18+5;
    for(auto elem: compList[i]){
      long long connectToN = closest(elem, compList[nNum]);
      minDistN = min(minDistN, (long long) (elem-connectToN) * (elem-connectToN));
    }
    ans = min(ans, minDistN+minDist1);
  }
  cout<<ans<<endl;
}

int main() {
  int t; cin>>t;
  while(t--){
    solve();
  }  
} 
