// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Time complexity : O(n^2)O(n2). For every element in the array, say i, we are looking at the next nums[i] elements to its right aiming to find a GOOD index. 
// nums[i] can be at most nn, where nn is the length of array nums.
// Space complexity : O(n)O(n). This comes from the usage of the memo table.

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
    return dp[nums.size() - 1] >= nums.size() - 1;
  }
};
