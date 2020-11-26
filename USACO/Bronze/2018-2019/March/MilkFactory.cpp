//DFS solution
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("factory.in");
ofstream fout("factory.out");

int n;
vector<int> adj[102];
bool visited[102];

void dfs(int node){
  cout<<node;
  visited[node] = true;
  for(auto u: adj[node]){
    if(!visited[u]) dfs(u);
  }
}

int main(){
  fin>>n;
  for(int i=0; i<n-1; i++){
    int a,b;
    fin>>a>>b;
    adj[b].push_back(a);
  }
  int ans = -1;
  for(int start=1; start<=n; start++){
    for(int i=1; i<=n; i++) visited[i] = false;
    dfs(start);
    bool done = true;
    for(int i=1; i<=n; i++){
      if(visited[i] == false) done = false;
    }
    if(done){
      ans = start;
      break;
    }
    cout<<endl;
  }
  fout<<ans;
}
