#include <bits/stdc++.h>
using namespace std;
ifstream fin("fenceplan.in");
ofstream fout("fenceplan.out");

int n, m, minPerimeter = 1e9;
pair<int, int> cowPos[100002];
vector<int> adj[100002];
int minX, maxX, minY, maxY;
bool visited[100002];

void dfs(int node){
  visited[node] = true;
  minX = min(cowPos[node].first,minX);
  maxX = max(cowPos[node].first,maxX);
  minY = min(cowPos[node].second,minY);
  maxY = max(cowPos[node].second,maxY);
  for(auto u: adj[node]){
    if(!visited[u]) dfs(u);
  }
}

int main() {
  fin>>n>>m;
  for(int i=1; i<=n; i++){
    fin>>cowPos[i].first>>cowPos[i].second;
  }
  for(int i=0; i<m; i++){
    int a,b;
    fin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i=1; i<=n; i++){
    if(!visited[i]){
      minX=1e9, maxX=0, minY=1e9, maxY=0;
      dfs(i);
      int perimeter = 2 * ((maxX-minX)+(maxY-minY));
      minPerimeter = min(minPerimeter,perimeter);
    }
  }
  fout<<minPerimeter;
}
