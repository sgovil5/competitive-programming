#include <iostream>
#include <vector>
using namespace std;

#define f first
#define s second

void setIO(string fileName = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)fileName.size()) {
		freopen((fileName+".in").c_str(), "r", stdin);
		freopen((fileName+".out").c_str(), "w", stdout);
	}
}

const int MX = 1e5+5;
int n, m;
vector<pair<int, char>> adj[MX];
bool vis[MX] = {false};
int color[MX] = {0};
bool possible = true;

void dfs(int node, int prevColor, bool same){
  vis[node] = true;
  if(prevColor==0) color[node] = 1;
  else{
    if(same==true) color[node] = prevColor;
    else color[node] = (prevColor==2 ? 1 : 2);
  }

  for(auto u: adj[node]){
    if(vis[u.f]){
      if(u.s=='S' && color[u.f]!=color[node]) possible = false;
      else if(u.s=='D' && color[u.f]==color[node]) possible = false;
    }
    else{
      dfs(u.f, color[node], (u.s=='S'?true:false));
    }
  }
}

int main(){
  //setIO("revegetate");
  cin>>n>>m;
  for(int i=0; i<m; i++){
    char x; int a, b; cin>>x>>a>>b;
    adj[a].push_back({b, x});
    adj[b].push_back({a, x});
  }

  int comp=0;
  for(int i=1; i<=n; i++){
    if(!vis[i]){
      comp++;
      dfs(i, 0, true);
    }
  }
  
  if(possible){
    cout<<1;
    for(int i=0; i<comp; i++) cout<<0;
    cout<<endl;
  }
  else cout<<0;

}