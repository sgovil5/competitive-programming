#include <bits/stdc++.h>
using namespace std;
ifstream fin("mootube.in");
ofstream fout("mootube.out");

int n,q;
pair<int,int> queries[5002]; //K, video
vector<pair<int,int>> adj[5002]; //video 2, relevance
bool visited[5002];
int k;

void dfs(int node){
  visited[node] = true;
  for(pair<int,int> u: adj[node]){
    if(u.second>=k&&!visited[u.first]){
      dfs(u.first);
    }
  }
}

int main() {
  fin>>n>>q;
  for(int i=1; i<=n-1; i++){
    int p,q,r;
    fin>>p>>q>>r;
    pair<int,int> p1 = make_pair(q,r);
    pair<int,int> p2 = make_pair(p,r);
    adj[p].push_back(p1);
    adj[q].push_back(p2);
  }
  for(int i=1; i<=q; i++){
    fin>>queries[i].first>>queries[i].second;
  }
  for(int i=1; i<=q; i++){
    k = queries[i].first;
    for(int i=1; i<=n; i++) visited[i]=false;
    dfs(queries[i].second);
    int counter = 0;
    for(int i=1; i<=n; i++) if(visited[i]==true) counter++;
    fout<<counter-1<<endl;
  }
}
