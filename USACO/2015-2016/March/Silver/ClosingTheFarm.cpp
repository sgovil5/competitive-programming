#include <bits/stdc++.h>
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
using namespace std;
ifstream fin("closing.in");
ofstream fout("closing.out");

int n,m;
vector<int> adj[3002];
bool visited[3002], unreachable[3002];
int closes[3002];

void dfs(int node){
  visited[node] = true;
  for(auto u: adj[node]){
    if(!visited[u]&&!unreachable[u]) dfs(u);
  }
}

int main(){
  fin>>n>>m;
  FOR(i, 0, m){
    int a,b;
    fin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  FOR(i, 0, n){
    fin>>closes[i];
  }
  FOR(i,0,n){
    FOR(i, 1, n+1) visited[i] = false;
    dfs(closes[n-1]);
    bool canReach = true;
    FOR(i, 1, n+1){
      if(!unreachable[i] && !visited[i]) canReach = false;
    }
    if(canReach) fout<<"YES"<<'\n';
    else fout<<"NO"<<'\n';
    unreachable[closes[i]] = true;
  }
}
