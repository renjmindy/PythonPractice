class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int maxSum = INT_MIN, minSum = INT_MAX, curMaxVal = 0, curMinVal = 0;
    int totSum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); i++) {
      curMaxVal = max(nums[i], curMaxVal + nums[i]);
      maxSum = max(maxSum, curMaxVal);
      
      curMinVal = min(nums[i], curMinVal + nums[i]);
      minSum = min(minSum, curMinVal);
    }
    if (totSum == minSum) {
      return maxSum;
    }
    return max(totSum - minSum, maxSum);
  }
};
