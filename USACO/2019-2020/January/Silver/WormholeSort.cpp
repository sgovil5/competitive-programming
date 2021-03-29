#include <bits/stdc++.h>
using namespace std;
ifstream fin("wormsort.in");
ofstream fout("wormsort.out");

#define f first
#define s second
typedef pair<int,int> pi;

const int MX = 1e5 + 5;
int n,m;
int startPos[MX];
int component[MX];
vector<pi> paths[MX]; // node, w

void dfs(int node, int compNum, int w){
  // add currently traversed node to current component being looked at
  component[node] = compNum;

  for(auto u: paths[node]){
    // visited if component has been considered before
    bool vis = (component[u.f]==-1 ? false : true);
    // make sure that current pathway meets width requirements
    if(!vis && u.s>=w) dfs(u.f, compNum, w);
  }
}

bool check(int w){
  // start component again for each w we check because paths change
  fill(begin(component), end(component), -1);
  int currComp = -1;
  
  // perform dfs to find all components that nodes belong to
  for(int i=0; i<n; i++){
    if(component[i]==-1) dfs(i, ++currComp, w);
  }

  // make sure swapped numbers are in the same components so they can travel back
  bool res = true;
  for(int i=0; i<n; i++){
    if(component[i]!=component[startPos[i]]) res = false;
  }
  return res;
}

// Find the greatest width for which its possible
int lastTrue(int lo, int hi) {
	for (--lo; lo < hi; ) {
		int mid = lo+(hi-lo+1)/2;
		if (check(mid)) lo = mid;
		else hi = mid-1;
	}
	return lo;
}

int main(){
  fin>>n>>m;
  for(int i=0; i<n; i++){
    fin>>startPos[i];
    startPos[i]--;
  }
  for(int i=0; i<m; i++){
    int a,b,w;
    fin>>a>>b>>w;
    a--,b--;
    paths[a].push_back({b,w});
    paths[b].push_back({a,w});
  }

  int ans = lastTrue(0, 1000000001);
  fout<<(ans == 1000000001 ? -1 : ans);
}
