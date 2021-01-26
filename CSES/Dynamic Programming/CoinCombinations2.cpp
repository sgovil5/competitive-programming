#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MX = 1e6+1;
int n,x;
int coins[MX]={0};
int dp[MX]={0};

int main() {
  cin>>n>>x;
  for(int i=0; i<n; i++) cin>>coins[i];
  dp[0] = 1;
  // Switched order of loops from Coin Combinations 1 because it ensures ordered pairs only
  //We update the weights using coins in the order we loop over them
  for(int c=1; c<=n; c++){
    for(int w=1; w<=x; w++){
      if(w-coins[c-1]>=0){
        dp[w] += dp[w-coins[c-1]];
        dp[w]%=(int) 1e9+7;
      }
    }
  }
  cout<<dp[x];
}
