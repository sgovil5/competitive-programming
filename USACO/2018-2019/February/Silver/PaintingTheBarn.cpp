#include <bits/stdc++.h>
using namespace std;
ifstream fin("paintbarn.in");
ofstream fout("paintbarn.out");

int main() {
  int n,k;
  fin>>n>>k;
  int p[1002][1002];
  while(n--){
    int a,b,c,d;
    fin>>a>>b>>c>>d;
    a++, b++, c++, d++;
    p[a][b]++;
    p[c][d]++;
    p[a][d]--;
    p[c][b]--;
  }
  int cnt = 0;
  for(int i=0; i<=1000; i++) p[i][0]=0, p[0][i]=0;
  for(int i=1; i<=1000; i++){
    for(int j=1; j<=1000; j++){
      p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
      if(p[i][j]==k) cnt++;
    }
  }
  fout<<cnt;
}
