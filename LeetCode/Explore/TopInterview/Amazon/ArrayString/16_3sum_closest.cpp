class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int minDiff = INT_MAX;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size() && minDiff != 0; i++) {
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
          int sum = nums[i] + nums[l] + nums[r];
          if (abs(target - sum) < abs(minDiff)) {
            minDiff = target - sum;
          }
          if (sum - target < 0) {
            l++;
          }
          else {
            r--;
          }
        }
      }
      return target - minDiff;
    }
};
