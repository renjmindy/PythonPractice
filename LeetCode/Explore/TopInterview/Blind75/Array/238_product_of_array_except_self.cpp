// two pass dynamical programming (bottom-up tabulation)
// Complexity analysis
// Time complexity : O(N)O(N) where NN represents the number of elements in the input array. 
// we use one iteration to construct the array LL, one to update the array answeranswer.
// Space complexity : O(1)O(1) since don't use any additional array for our computations.
// The problem statement mentions that using the answeranswer array doesn't add to the space complexity.

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int mul = 1;
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
      dp[i] *= mul;
      mul *= nums[i]; 
      // dp[i] = dp[i - 1] * nums[i - 1];
    }
    mul = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      dp[i] *= mul;
      mul *= nums[i];
    }
    return dp;
  }
};
