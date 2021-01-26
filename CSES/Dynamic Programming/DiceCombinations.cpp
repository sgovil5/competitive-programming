#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int dp[1000002] = {0};
  dp[0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=6; j++){
      if(i-j>=0){
        dp[i] += dp[i-j];
        dp[i] %= 1000000007;
      }
    }
  }
  cout<<dp[n];
}
