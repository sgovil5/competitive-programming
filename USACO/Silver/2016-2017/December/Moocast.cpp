#include <bits/stdc++.h>
using namespace std;
using pii=pair<int, int>;
ifstream fin("moocast.in");
ofstream fout("moocast.out");
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define fi first
#define se second

int n;
pair<pii,int> cows[202]; //{x,y,p}
bool visited[202];
vector<int> adj[202];
int cowsReached;

void dfs(int node){
  visited[node] = true;
  cowsReached++;
  for(auto u: adj[node]){
    if(!visited[u]) dfs(u);
  }
}

int main(){
  fin>>n;
  FOR(i, 0, n){
    fin>>cows[i].fi.fi>>cows[i].fi.se>>cows[i].se;
  }
  FOR(i, 0, n){
    FOR(j,0,n){
      if(i!=j){
        double dist = sqrt(pow(cows[i].fi.fi-cows[j].fi.fi,2)+pow(cows[i].fi.se-cows[j].fi.se,2));
        if(dist<=cows[i].se){
          adj[i].pb(j);
        }
      }
    }
  }
  int maxCows = 0;
  FOR(i,0,n){
    FOR(i,0,n) visited[i] =false;
    cowsReached = 0;
    dfs(i);
    maxCows =  max(cowsReached, maxCows);
  }
  fout<<maxCows;
}
