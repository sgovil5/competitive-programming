#include <bits/stdc++.h>
using namespace std;
ifstream fin("paintbarn.in");
ofstream fout("paintbarn.out");

const int MX = 1005;

int main(){
  int n,k; fin>>n>>k;
  int g[MX][MX];
  for(int i=0; i<MX; i++){
    for(int j=0; j<MX; j++){
      g[i][j] = 0;
    }
  }

  for(int i=0; i<n; i++){
    int x1, y1, x2, y2; fin>>x1>>y1>>x2>>y2;
    for(int j=y1; j<y2; j++){
      g[x1][j]++, g[x2][j]--;
    }
  }

  int ans = 0;
  for(int i=1; i<MX; i++){
    for(int j=1; j<MX; j++){
      g[i][j] += g[i-1][j];
      if(g[i][j]==k) ans++; 
    }
  }
  fout<<ans<<endl;
}
