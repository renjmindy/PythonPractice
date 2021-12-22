class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size() + 1);
        dp[nums.size()] = 0;
        dp[nums.size() - 1] = nums.at(nums.size() - 1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            dp[i] = max(dp[i+1], dp[i+2]+nums.at(i));
        }
        return dp[0];
    }
};
