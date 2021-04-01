#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int grid[n][n];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>grid[i][j];
    }
  }

  // Calculate horizontal
  int horizontal = 0;
  for(int i=0; i<n; i++){
    int even = 0, odd = 0;
    for(int j=0; j<n; j+=2){
      even+=grid[i][j];
    }
    for(int j=1; j<n; j+=2){
      odd+=grid[i][j];
    }
    horizontal+=max(odd, even);
  }
  //Calculate vertical
  int vertical = 0;
  for(int i=0; i<n; i++){
    int even = 0, odd = 0;
    for(int j=0; j<n; j+=2){
      even+=grid[j][i];
    }
    for(int j=1; j<n; j+=2){
      odd+=grid[j][i];
    }
    vertical+=max(odd, even);
  }
  cout<<max(vertical, horizontal);
}
