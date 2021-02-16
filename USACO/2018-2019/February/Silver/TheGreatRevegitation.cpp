#include <bits/stdc++.h>
using namespace std;
ifstream fin("revegetate.in");
ofstream fout("revegetate.out");

#define f first
#define s second

const int MX = 1e5+5;

int n, m;
vector<pair<int, char>> adj[MX];
bool vis[MX], grass[MX];
bool ok = true;

void dfs(int node, bool color){
  vis[node] = true;
  grass[node] = color;
  for(auto u: adj[node]){
    if(vis[u.f]){
      if(u.s=='S' && grass[u.f]!=color) ok = false;
      else if(u.s=='D' && grass[u.f]==color) ok = false;
    }
    else{
      if(u.s=='S'){
        dfs(u.f, color);
      }
      else if(u.s=='D'){
        dfs(u.f, !color);
      }
    }
  }
}

int main(){
  fin>>n>>m;
  for(int i=0; i<m; i++){
    char d;
    int a,b;
    fin>>d>>a>>b;
    adj[a].push_back({b,d});
    adj[b].push_back({a,d});
  }
  for(int i=0; i<=n; i++){vis[i] = false;}
  if(!ok) fout<<0;
  else{
    int count = 0;
    for(int i=1; i<=n; i++){
      if(!vis[i]){
        dfs(i, true);
        count++;
      }
    }
    string ans = "1";
    for(int i=0; i<count; i++){
      ans+="0";
    }
    fout<<ans;
  }
}
