class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            dp[i] = INT_MAX;
        }
        for (int i = 1; i < amount + 1; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins.at(j) <= i) {
                    if (dp.at(i - coins.at(j)) != INT_MAX) {
                        dp.at(i) = min(dp.at(i), dp.at(i - coins.at(j)) + 1);
                    }
                }
            }
        }
        return (dp[amount] != INT_MAX) ? dp[amount] : -1;
    }
};
