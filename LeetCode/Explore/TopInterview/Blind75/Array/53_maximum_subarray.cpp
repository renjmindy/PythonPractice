// one pass dynamical programming, Kadane's Algorithm
// Complexity Analysis
// Time complexity: O(N)O(N), where NN is the length of nums.
// We iterate through every element of nums exactly once.
// Space complexity: O(1)O(1)
// No matter how long the input is, we are only ever using 2 variables: currentSubarray and maxSubarray.
  
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, curVal = 0;
    for (int i = 0; i < nums.size(); i++) {
      curVal = max(nums[i], curVal + nums[i]); // curVal either re-set to be current value or kept to be summed up 
      maxSum = max(maxSum, curVal);
    }
    return maxSum;
  }
};
