#include <bits/stdc++.h>
using namespace std;

int n,m;
string grid[2500];
bool visited[2500][2500];
const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};

void floodfill(int x, int y){
  if(x<0||x>=n||y<0||y>=m||grid[x][y]=='#'||visited[x][y]) return;
  visited[x][y] = true;
  for(int i=0; i<4; i++) floodfill(x+xd[i], y+yd[i]);
}

int main() {
  cin>>n>>m;
  for(int i=0; i<n; i++){
    cin>>grid[i];
  }
  int roomCount = 0;
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if(!visited[i][j]&&grid[i][j]=='.'){
        floodfill(i, j);
        roomCount++;
      }
    }
  }
  cout<<roomCount;
}
