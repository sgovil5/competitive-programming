#include <bits/stdc++.h>
using namespace std;
ifstream fin("countcross.in");
ofstream fout("countcross.out");

#define f first
#define s second

const int MX = 102;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int n, k, r;
vector<pair<int, int>> p;
map<pair<pair<int,int>, pair<int,int>>, bool>  roads;
int cmp[MX][MX];

void ff(int x, int y, int cmpNum){
  if(x<0 || x>=n || y<0 || y>=n) return;
  cmp[x][y] = cmpNum;

  for(int d=0; d<4; d++){
    int xx = x+dx[d], yy = y+dy[d];
    if(cmp[xx][yy]==-1 && roads[{{x, y}, {xx, yy}}]!=true){
      ff(xx, yy, cmpNum);
    }
  }
}

int main(){
  fin>>n>>k>>r;
  for(int i=0; i<r; i++){
    int r, c, r1, c1; fin>>r>>c>>r1>>c1;
    r--, c--, r1--, c1--;
    roads[{{r,c}, {r1,c1}}] = true;
    roads[{{r1,c1}, {r,c}}] = true;
  }
  for(int i=0; i<k; i++){
    int x, y; fin>>x>>y;
    x--, y--;
    p.push_back({x,y});
  }

  for(int i=0; i<MX; i++) for(int j=0; j<MX; j++) cmp[i][j] = -1;

  int cmpNum = -1;
  for(int i=0; i<k; i++){
    if(cmp[p[i].f][p[i].s]==-1) ff(p[i].f, p[i].s, ++cmpNum);
  }

  int ans = 0;
  for(int i=0; i<k; i++){
    for(int j=i+1; j<k; j++){
      if(cmp[p[i].f][p[i].s]!=cmp[p[j].f][p[j].s]) ans++;
    }
  }

  fout<<ans;
}
