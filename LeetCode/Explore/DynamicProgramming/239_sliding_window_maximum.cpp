class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.size() * k == 0) {
      return {0};
    }
    if (k == 1) {
      return nums;
    }
    
    vector<int> dpl(nums.size()), dpr(nums.size()), ans(nums.size() - k + 1);
    dpl[0] = nums[0];
    dpr[nums.size() - 1] = nums[nums.size() - 1];
    
    for (int l = 1; l < nums.size(); l++) {
      if (l % k == 0) {
        dpl[l] = nums[l];
      }
      else {
        dpl[l] = max(dpl[l - 1], nums[l]);
      }
      
      int r = nums.size() - l - 1;
      if ((r + 1) % k == 0) {
        dpr[r] = nums[r];
      }
      else {
        dpr[r] = max(dpr[r + 1], nums[r]);
      }
    }
    
    for (int i = 0; i < nums.size() - k + 1; i++) {
      ans[i] = max(dpl[i + k - 1], dpr[i]);
    }
    
    return ans;
  }
};
