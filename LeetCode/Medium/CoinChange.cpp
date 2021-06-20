class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i=1; i<=amount; i++) dp[i] = INT_MAX-1;
        
        dp[0] = 0;
        for(int j=1; j<=amount; ++j){
            for(auto c: coins){
                if(c<=j){
                    dp[j] = min(dp[j], dp[j-c]+1);
                }
            }
        }
        return dp[amount]==INT_MAX-1?-1:dp[amount];
    }
};
