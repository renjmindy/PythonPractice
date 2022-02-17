class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      int sum = accumulate(nums.begin(), nums.end(), 0);
      vector<int> dp(2*sum + 1);
      dp[nums[0] + sum] = 1;
      dp[-nums[0] + sum] += 1;
      
      for (int i = 1; i < nums.size(); i++) {
        vector<int> np(2*sum + 1);
        for (int j = -sum; j <= sum; j++) {
          if (dp[j + sum] > 0) {
            np[j + nums[i] + sum] += dp[j + sum];
            np[j - nums[i] + sum] += dp[j + sum];
          }
        }
        dp = np;
      }
      return abs(target) > sum ? 0 : dp[target + sum];
    }
};
