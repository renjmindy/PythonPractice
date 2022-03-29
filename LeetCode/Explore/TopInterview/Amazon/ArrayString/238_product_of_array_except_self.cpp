class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int mul = 1;
      vector<int> dp(nums.size(), 1);
      
      for (int i = 0; i < nums.size(); i++) {
        dp[i] *= mul;
        mul *= nums[i];
      }
      
      mul = 1;
      for (int i = nums.size() - 1; i >= 0; i--) {
        dp[i] *= mul;
        mul *= nums[i];
      }
      
      return dp;
    }
};
