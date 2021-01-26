#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n,x;
const int MX = 1e6+1;
int coins[102];
ll dp[MX];

int main() {
  cin>>n>>x;
  for(int i=0; i<n; i++){
    cin>>coins[i];
  }
  // IDK why i can't just initialize it in the top, but it doesn't work
  for(int i=0; i<=x; i++){
    dp[i] = INT_MAX;
  }
  dp[0] = 0;
  for(int i=1; i<=n; i++){
    for(int w = 0; w<=x; w++){
      if(w-coins[i-1]>=0){
        dp[w] = min(dp[w], dp[w-coins[i-1]]+1);
      }
    }
  }
  cout<<(dp[x]==INT_MAX ? -1 : dp[x]);
}
