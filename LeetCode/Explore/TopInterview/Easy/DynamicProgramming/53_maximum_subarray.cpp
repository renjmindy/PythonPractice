class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, curVal = 0;
    for (int i = 0; i < nums.size(); i++) {
      curVal = max(nums[i], curVal + nums[i]);
      maxSum = max(maxSum, curVal);
    }
    return maxSum;
  }
};
