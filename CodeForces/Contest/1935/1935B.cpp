#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> dp(200, 1e9+5);

void solve() {
    int n; cin>>n;
    vector<int> coins = {1, 3, 6, 10, 15};
    dp[0] = 0;

    for (int i=1; i<=100; i++) {
        for (int coin: coins) {
            if(i-coin >= 0) {
                dp[i] = min(dp[i], dp[(i-coin)]+1);
            }
        }
    }
    if(n<=100) {
        cout<<dp[n]<<endl;
        return;
    }
    for(int c: coins) {
        dp[c] = 1;
    }
    int cost1 = n/15; int val1 = 15*cost1;
    int rem1 = n - val1;
    cost1 += dp[rem1];

    int cost2 = (n-35)/15; int val2 = 15*((n-35)/15);
    int rem2 = n - val2;
    cost2 += dp[rem2];

    cout<<min(cost1, cost2)<<endl;
    
    // for(int i=50; i<=n; i++) {
    //     cout<<i<<" "<<dp[i]<<"|"<<i/15<<" "<<15*(i/15)<<"|"<<3+(i-35)/15<<" "<<15*((i-35)/15)<<endl;
    // }
}

int main() {
    int t; cin>>t;
    while(t--) {
        solve();
    }
}