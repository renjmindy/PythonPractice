class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums.at(i) > nums.at(j)) {
                    dp.at(i) = max(dp.at(i), dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
