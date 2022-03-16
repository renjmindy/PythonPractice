// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Time complexity : O(N)O(N) where NN is the size of nums. We are accumulating results as we are scanning nums.
// Space complexity : O(1)O(1) since we are not consuming additional space other than variables for two previous 
// results and a temporary variable to hold one of the previous results.

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) { // base case
      return 0;
    }
    if (nums.size() == 1) { // base case
      return nums[0];
    }
    if (nums.size() == 2) { // base case
      return max(nums[0], nums[1]);
    }
    vector<int> dp(nums.size(), 0);
    // backward; leave first house
    dp[nums.size() - 1] = nums[nums.size() - 1];
    dp[nums.size() - 2] = max(nums[nums.size() - 1], nums[nums.size() - 2]);
    for (int i = nums.size() - 3; i >= 1; i--) {
      dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    }
    int tmp1 = dp[1];
    // forward; leave last house
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size() - 1; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    int tmp2 = dp[nums.size() - 2];
    return max(tmp1, tmp2);
  }
};
