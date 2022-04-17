class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int l = nums.size() - 2, r = nums.size() - 1;
      while (l >= 0 && nums[l] >= nums[l + 1]) {
        l--;
      }
      if (l >= 0) {
        while (r > l && nums[r] <= nums[l]) {
          r--;
        }
        swap(nums[l], nums[r]);
      }
      reverse(nums.begin() + l + 1, nums.end());
    }
};
