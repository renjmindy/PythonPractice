class Solution {
public:
    int search(vector<int>& nums, int target) {
      int pivot, l = 0, r = nums.size() - 1;
      while (l <= r) {
        pivot = l + (r - l) / 2;
        if (nums[pivot] == target) {
          return pivot;
        }
        if (nums[l] <= nums[pivot]) {
          if (nums[pivot] >= target && nums[l] <= target) {
            r = pivot - 1;
          }
          else {
            l = pivot + 1;
          }
        }
        else {
          if (nums[pivot] <= target && nums[r] >= target) {
            l = pivot + 1;
          }
          else {
            r = pivot -1;
          }
        }
      }
      return -1;
    }
};
