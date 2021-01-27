#include <bits/stdc++.h>
using namespace std;

int n,x;
int price[1001];
int pages[1001];

int main() {
  cin>>n>>x;
  for(int i=0; i<n; i++) cin>>price[i];
  for(int i=0; i<n; i++) cin>>pages[i];
  vector<vector<int>> dp(n+1, vector<int>(x+1,0));
  for(int p=1; p<=n; p++){
    for(int w=0; w<=x; w++){
      dp[p][w] = dp[p-1][w];
      if(w-price[p-1]>=0){
        dp[p][w] = max(dp[p][w], dp[p-1][w-price[p-1]]+pages[p-1]);
      } 
    }
  }
  cout<<dp[n][x];
}
