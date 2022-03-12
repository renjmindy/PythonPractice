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
      //cout << dp[i] << endl;
      if (dp[i] >= nums.size() - 1) {
        return true;
      }
      if (dp[i] == 0) {
        return false;
      }
    }
    return dp[nums.size() - 1] >= nums.size() - 1;
  }
};
