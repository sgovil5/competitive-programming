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
  for(int w=1; w<=x; w++){
    for(int c=0; c<n; c++){
      if(w-coins[c]>=0){
        dp[w] += dp[w-coins[c]];
        dp[w]%=(int) 1e9+7;
      }
    }
  }
  cout<<dp[x];
}
