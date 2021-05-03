#include <bits/stdc++.h>
using namespace std;
ifstream fin("moocast.in");
ofstream fout("moocast.out");

#define f first
#define s second

const int MX = 1005;

int n;
vector<pair<int,int>> points;
bool vis[MX];

void dfs(int node, vector<int> adj[]){
  vis[node] = true;
  for(auto u: adj[node]){
    if(!vis[u]) dfs(u, adj);
  }
}

bool check(int maxDist){
  vector<int> adj[MX];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int dist = pow(points[i].f-points[j].f,2) + pow(points[i].s-points[j].s,2);
      if(dist<=maxDist){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  for(int i = 0; i<MX; i++) vis[i] = false;

  dfs(0, adj);

  bool possible = true;
  for(int i=0; i<n; i++) {
    if(!vis[i]){
      possible = false;
    }
  }

  return possible;
}

int firstTrue(int lo, int hi){
	for (hi ++; lo < hi; ) {
		int mid = lo+(hi-lo)/2;
		if (check(mid)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main(){
  fin>>n;
  for(int i=0; i<n; i++){
    int a,b;
    fin>>a>>b;
    points.push_back({a,b});
  }

  fout<<firstTrue(0, 1000000000);
}
