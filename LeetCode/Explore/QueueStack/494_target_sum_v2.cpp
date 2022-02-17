class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      int sum = accumulate(nums.begin(), nums.end(), 0);
      int new_sum = sum + target;
      if (sum < target || new_sum % 2 != 0 || new_sum < 0) {
        return 0;
      }
      vector<int> dp((new_sum/2) + 1, 0);
      dp[0] = 1;
      for (int i = 0; i < nums.size(); i++) {
        for (int j = (new_sum/2); j >= nums[i]; j--) {
          dp[j] += dp[j - nums[i]];
        }
      }
      return dp[new_sum/2];
    }
};
