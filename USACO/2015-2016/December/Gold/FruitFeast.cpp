#include <bits/stdc++.h>
using namespace std;
ifstream fin("feast.in");
ofstream fout("feast.out");

int main(){
  int t,a,b;
  fin>>t>>a>>b;
  //Vector where row 1 = no water, row2 = water 
  vector<vector<int>> dp(2, vector<int>(t+1, false));
  dp[0][0] = true, dp[1][0] = true;
  // Calculate all fullness without drinking water
  for(int i=1; i<=t; i++){
    if(i-a>=0 && dp[0][i-a]==true) dp[0][i] = true;
    if(i-b>=0 && dp[0][i-b]==true) dp[0][i] = true;
  }
  //Calculate fullness after drinking water
  for(int i=1; i<=t; i++){
    // Check double the current amount to see
    // If water can be taken at double the amount
    // In order to halve fullness to curr i
    if(i<=(t/2)){
      if(dp[0][2*i]==true || dp[0][(2*i)+1]==true){
        dp[1][i] = true;
      }
    }
    // Check previous fullness in water state
    if(i-a>=0 && dp[1][i-a]==true) dp[1][i] = true;
    if(i-b>=0 && dp[1][i-b]==true) dp[1][i] = true;
  }
  int maxFull = 0;
  for(int i=0; i<=t; i++){
    if(dp[0][i]||dp[1][i]) maxFull = i;
  }
  fout<<maxFull<<endl;
}
