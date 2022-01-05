#include <bits/stdc++.h>
using namespace std; 
ifstream fin("lazy.in");
ofstream fout("lazy.out");

int main() {
  int n, k; fin>>n>>k;
  int g[n][n];
  int prefix[n][n+1];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      fin>>g[i][j];
    }
  }

  for(int i=0; i<n; i++){
    prefix[i][0] = 0;
  }
  for(int i=0; i<n; i++){
    for(int j=1; j<=n; j++){
      prefix[i][j] = prefix[i][j-1] + g[i][j-1];
    }
  }
  
  int ans = 0;
  for(int i=0; i<n; i++){
    for(int j=1; j<=n; j++){
      int tempAns = 0;

      for(int y=i; y>=i-k && y>=0; y--){
        int radius = k-(i-y);
        tempAns+=prefix[y][min(n, j+radius)]-prefix[y][max(1, j-radius)-1];
      }

      for(int y=i+1; y<=i+k && y<n; y++){
        int radius = k-(y-i);
        tempAns+=prefix[y][min(n, j+radius)]-prefix[y][max(1, j-radius)-1];
      }
      ans = max(tempAns, ans);
    }
  }
  fout<<ans<<endl;
} 
