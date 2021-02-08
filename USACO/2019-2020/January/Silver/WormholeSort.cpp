#include <bits/stdc++.h>
using namespace std;
ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

#define f first
#define s second

const int MX = 1e5+2;
int n,m;
vector<pair<int,int>> adj[MX]; //a,b,w
vector<int> arr(MX), component(MX);

void dfs(int node, int label, int w){
  component[node] = label;
  for(auto u: adj[node]){
    if(!(u.s<w || component[u.f] !=-1)) dfs(u.f, label, w);
  }
}

bool check(int width){
  fill(component.begin(), component.end(), -1);
  int label = -1;
  for(int i=0; i<n; i++){
    if(component[i]==-1) dfs(i, ++label, width);
  }
  bool ans = true;
  for(int i=0; i<n; i++){
    if(component[i]!=component[arr[i]]) ans = false;
  }
  return ans;
}

int main(){
  fin>>n>>m;
  for(int i=0; i<n; i++) {
    fin>>arr[i];
    arr[i]--;
  }
  for(int i=0; i<m; i++){
    int a,b,w;
    fin>>a>>b>>w;
    a--, b--;
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
  }
  int sol = -1;
  int lo = 1, hi = 1e9 + 1;
  int top = hi;
  while (lo <= hi) {
    int mid = lo + (hi - lo)/2;

    if (check(mid)) {
      sol = max (sol, mid);
      lo = mid + 1;
    } 
    else {
      hi = mid - 1;
    }
  }
  fout<<(sol == top ? -1 : sol);
} 
