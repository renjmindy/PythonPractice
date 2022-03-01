class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    int mul = 1;
    for (int i = 0; i < nums.size(); i++) {
      ans[i] *= mul;
      mul *= nums[i];
    }
    mul = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      ans[i] *= mul;
      mul *= nums[i];
    }
    return ans;
  }
};
