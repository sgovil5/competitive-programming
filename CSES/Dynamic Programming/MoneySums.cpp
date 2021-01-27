#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int arr[n];
  //the max weight we can construct is the sum of all the coins
  int sum = 0;
  for(int i=0; i<n; i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  vector<vector<bool>> dp(n+1, vector<bool>(sum+1,false));
  // We can create a value of 0 with our coins so initialize all 0s o true
  for(int i=0; i<=n; i++) dp[i][0] = true;
  for(int i=1; i<=n; i++){ // look at all the coins
    for(int j=0; j<=sum; j++){ //look at all the numbers not greater than sum
      // If we could have made the sum with the previous i-1 coins:
      // DP of the current number with i coins will be true
      dp[i][j] = dp[i-1][j];
      //If we can make the target sum with the new coin we just introduced:
      // DP of the current sum and amount of coins is true
      if(j-arr[i-1]>=0) if(dp[i-1][j-arr[i-1]]) dp[i][j] = true;
    }
  }
  int k = 0;
  for(int i=1; i<=sum; i++) if(dp[n][i]) k++;
  cout<<k<<endl;
  // If we can make the sum with all of the coins introduced, we add it to the output
  for(int i=1; i<=sum; i++) if(dp[n][i]) cout<<i<<" ";
}
