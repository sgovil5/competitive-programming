#include <bits/stdc++.h>
using namespace std;
ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

const int MX = 255;

int n,b;
int ans = 255;
vector<int> field; //field[i] is depth at tile i
vector<pair<int, int>> shoes; // max depth, distance
vector<vector<bool>> vis(MX, vector<bool>(MX, false));


void dfs(int currDist, int currBoot){
  if(vis[currDist][currBoot]) return;
  vis[currDist][currBoot] = true;

  if(currDist == n-1){
    ans = min(currBoot, ans); return;
  }

  for(int i=currDist; i<=currDist+shoes[currBoot].second && i<n; i++){
    if(shoes[currBoot].first>=field[i]) dfs(i, currBoot); 
  }

  for(int i=currBoot; i<b; i++){
    if(field[currDist] <= shoes[i].first){
      dfs(currDist, i);
    }
  }
}

int main() {
  fin>>n>>b;
  for(int i=0; i<n; i++){
    int x; fin>>x;
    field.push_back(x);
  }
  for(int i=0; i<b; i++){
    int s, d; fin>>s>>d;
    shoes.push_back({s,d});
  }

  dfs(0, 0);
  fout<<ans;
} 
