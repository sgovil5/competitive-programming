#include <bits/stdc++.h>
using namespace std;
ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

const int MXN = 1e5 + 5;
int n,m;
string s;
vector<int> adj[MXN];
char breed[MXN];
int component[MXN];
int componentNum;

void dfs(int node){
  if(component[node]) return;
  component[node] = componentNum;
  for(auto u: adj[node]){
    if(breed[node]==breed[u]) dfs(u);
  }
}

int main() {
  fin>>n>>m>>s;
  for(int i=1; i<=n; i++) breed[i] = s[i-1]; 
  for(int i=0; i<n-1; i++){
    int a,b;
    fin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1; i<=n; i++){
    if(!component[i]){
      componentNum++;
      dfs(i);
    }
  }
  for(int i=0; i<m; i++){
    int a,b;
    char c;
    fin>>a>>b>>c;
    if(breed[a]==c || component[a]!=component[b]) fout<<1;
    else fout<<0;
  }
}
