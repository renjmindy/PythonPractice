class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int curVal = nums[0], maxSum = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        curVal = max(nums[i], curVal + nums[i]);
        maxSum = max(maxSum, curVal);
      }
      return maxSum;
    }
};
