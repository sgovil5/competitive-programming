#include <bits/stdc++.h>
using namespace std;
ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

const int MX = 1e5+5;

int n,m;
int component[MX];
vector<int> adj[MX];
bool vis[MX];
char type[MX];
vector<pair<pair<int,int> , char>> queries;

void dfs(int node, int comp){
  vis[node] = true;
  component[node] = comp;
  for(auto u: adj[node]){
    if(!vis[u] && type[node]==type[u]) dfs(u, comp);
  }
}

int main(){
  //Input
  fin>>n>>m;
  string s;
  fin>>s;
  for(int i=0; i<n; i++) type[i+1] = s[i];
  for(int i=0; i<n-1; i++){
    int a,b; fin>>a>>b;
    adj[a].push_back(b), adj[b].push_back(a);
  }
  for(int i=0; i<m; i++){
    int a,b;
    char c;
    fin>>a>>b>>c;
    queries.push_back({{a,b},c});
  }
  fill(vis, vis+n+1, false);

  //Calculate component
  int currComp = 0;
  for(int i=1; i<=n; i++){
    if(!vis[i]){
      dfs(i, ++currComp);
    }
  }

  // Calculate queries
  for(int i=0; i<m; i++){
    int a = queries[i].first.first;
    int b = queries[i].first.second;
    char c = queries[i].second;
    if(component[a] == component[b]){
      if(c==type[a]) fout<<1;
      else fout<<0;
    }
    else{
      fout<<1;
    }
  }
}
