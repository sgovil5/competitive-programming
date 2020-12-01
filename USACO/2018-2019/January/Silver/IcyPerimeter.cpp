#include <bits/stdc++.h>
using namespace std;
ifstream fin("perimeter.in");
ofstream fout("perimeter.out");

const int xd[4] = {0,1,0,-1}, yd[4] = {1,0,-1,0};

int n;
string graph[1001];
bool vis[1001][1001];
int perimeter = 0;
int area = 0;

void ff(int x, int y){
  if(x<0 || x>=n || y < 0 ||y>=n || graph[x][y]=='.'){
    perimeter++;
    return;
  }
  else if(vis[x][y]) return;
  vis[x][y] = true;
  area++;
  for(int i=0; i<4; i++) ff(x+xd[i], y+yd[i]); // FF all directions
}

int main() {
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>graph[i];
  }  
  int maxArea = 0;
  int minPerimeter = 1e9;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(graph[i][j] == '#' && !vis[i][j]){
        ff(i,j);
        if(area  > maxArea){
          maxArea = area;
          minPerimeter = perimeter;
        }
        else if(area == maxArea){
          minPerimeter = min(minPerimeter, perimeter);
        }
      }
      perimeter = 0;
      area = 0;
    }
  }
  fout<<maxArea<<" "<<minPerimeter;
}
