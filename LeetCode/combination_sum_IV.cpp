class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i < target + 1; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums.at(j) >= 0) {
                    dp[i] += dp[i - nums.at(j)];
                }
            }
        }
        return dp[target];
    }
};
