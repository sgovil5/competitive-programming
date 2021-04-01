#include <bits/stdc++.h>
using namespace std;
ifstream fin("countcross.in");
ofstream fout("countcross.out");

#define f first
#define s second
typedef pair<int,int> pii;

const int MX = 101;
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};

int n,k,r, nCows;
int grid[MX][MX];
bool vis[MX][MX];
set<tuple<int,int,int,int>> roads;

void ff(int r, int c, int prevR, int prevC){
  if(r>=n || r<0 || c>=n || c<0 || vis[r][c] || roads.count(tie(r,c,prevR,prevC))) return;

  vis[r][c] = true;
  nCows += grid[r][c];

  for(int i=0; i<4; i++){
    ff(r + xd[i], c + yd[i], r, c);
  }
}

int main() {
  fin>>n>>k>>r;
  
  for(int i=0; i<r; i++){
    int r, c, r1, c1;
    fin>>r>>c>>r1>>c1;
    r--, c--, r1--, c1--;
    tuple<int, int, int, int> cur = tie(r,c,r1,c1);
		tuple<int, int, int, int> cur1 = tie(r1,c1,r,c);
		roads.insert(cur);
		roads.insert(cur1);
  }

  for(int i=0; i<k; i++){
    int r,c;
    fin>>r>>c;
    r--, c--;
    grid[r][c]++;
  }

  for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) vis[i][j] = false;

  vector<int> components;
  int totalCows = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(!vis[i][j]){
        nCows = 0;
        ff(i,j, -1, -1);
        totalCows+=nCows;
        if(nCows) components.push_back(nCows);
      }
    }
  }
  
  int sol = 0;
  for(int i=0; i<components.size(); i++){
    for(int j=i+1; j<components.size(); j++){
      sol+=components[i] * components[j];
    }
  }

  fout<<sol;
}
