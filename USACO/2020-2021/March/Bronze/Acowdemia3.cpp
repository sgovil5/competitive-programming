#include <bits/stdc++.h>
using namespace std;

const int MX = 1005;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int n,m;
char grid[MX][MX];

bool valid(int i, int j){
  return 0<=i && i<n && 0<=j && j<m && grid[i][j] == 'C';
}

int main(){
  cin>>n>>m;
  for(int i = 0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>grid[i][j];
    }
  }

  int ans = 0;
  set<vector<pair<int,int>>> pairs;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j] == 'G'){
        vector<pair<int,int>> adj;

        for(int d=0; d<4; d++){
          int ix = i+dx[d], jy = j+dy[d];
          if(valid(ix, jy)) adj.push_back({ix, jy});
        }

        if(adj.size()>2){
          ans++;
        } else if(adj.size()==2){
          sort(begin(adj), end(adj));
          pairs.insert(adj);
        }
      }
    }
  }

  cout<<pairs.size()+ans<<endl;
}
