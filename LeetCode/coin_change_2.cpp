class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins.at(i); j < amount + 1; j++) {
                dp[j] += dp[j - coins.at(i)];
            }
        }
        return dp[amount];
    }
};
