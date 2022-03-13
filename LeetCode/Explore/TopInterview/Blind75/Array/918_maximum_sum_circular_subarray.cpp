// one pass dynamical programming, Kadane's Algorithm
// Complexity Analysis
// Time Complexity: O(N)O(N), where NN is the length of A.
// Space Complexity: O(1)O(1) in additional space complexity.

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int maxSum = INT_MIN, minSum = INT_MAX, curMax = 0, curMin = 0;
    int totSum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); i++) {
      curMax = max(nums[i], nums[i] + curMax);
      maxSum = max(maxSum, curMax);
      curMin = min(nums[i], nums[i] + curMin); 
      minSum = min(minSum, curMin);
    }
    return totSum == minSum ? maxSum : max(maxSum, totSum - minSum);
  }
};
