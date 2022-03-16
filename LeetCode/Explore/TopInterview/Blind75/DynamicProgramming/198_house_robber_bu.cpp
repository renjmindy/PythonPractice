// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Time Complexity: O(N)O(N) since we have a loop from N - 2 \cdots 0N−2⋯0 and we simply use the pre-calculated values of our dynamic programming table for calculating 
// the current value in the table which is a constant time operation.
// Space Complexity: O(N)O(N) which is used by the table. So what is the real advantage of this solution over the previous solution? 
// In this case, we don't have a recursion stack. When the number of houses is large, a recursion stack can become a serious limitation, because the recursion stack size 
// will be huge and the compiler will eventually run into stack-overflow problems (no pun intended!).

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[nums.size() - 1];
  }
};
