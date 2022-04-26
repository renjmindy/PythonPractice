class Solution {
public:
    bool canJump(vector<int>& nums) {
      vector<int> dp(nums.size(), 0);
      dp[0] = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        if (dp[i - 1] < i) {
          return false;
        }
        dp[i] = max(dp[i - 1], i + nums[i]);
      }
      return true;
    }
};
