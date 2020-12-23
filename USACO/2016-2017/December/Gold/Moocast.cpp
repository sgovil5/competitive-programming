#include <bits/stdc++.h>
using namespace std;
ifstream fin("moocast.in");
ofstream fout("moocast.out");

int n;
int pos[1002][2];
bool visited[1002];

void dfs(int node, vector<int> adj[]){
  visited[node] = true;
  for(auto u: adj[node]){
    if(!visited[u]) dfs(u, adj);
  }
}

bool check(int r){
  fill(visited, visited+n, false);
  vector<int> adj[n];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(pow(pos[j][0]-pos[i][0],2) + pow(pos[j][1]-pos[i][1],2)<=r){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  dfs(0, adj);
  bool possible = true;
  for(int i=0; i<n; i++){
    if(visited[i]==false) possible = false;
  }
  return possible;
}

int fstTrue(int lo, int hi) {
    // returns smallest x in [lo,hi] that satisfies f
    // hi+1 if no x satisfies f
    for (hi ++; lo < hi; ) {
        int mid = (lo+hi)/2;
        check(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}

int main() {
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>pos[i][0]>>pos[i][1];
  }
  int ans = fstTrue(0, 1000000000);
  fout<<ans;
}
