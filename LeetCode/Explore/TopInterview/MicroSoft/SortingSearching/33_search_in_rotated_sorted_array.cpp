class Solution {
public:
    int search(vector<int>& nums, int target) {
      int pivot, l = 0, r = nums.size() - 1;
      while (l <= r) {
        pivot = l + (r - l) / 2;
        if (nums[pivot] == target) {
          return pivot;
        }
        else if (nums[pivot] >= nums[l]) {
          if (target >= nums[l] && target < nums[pivot]) {
            r = pivot - 1;
          }
          else {
            l = pivot + 1;
          }
        }
        else {
          if (target > nums[pivot] && target <= nums[r]) {
            l = pivot + 1;
          }
          else {
            r = pivot - 1;
          }
        }
      }
      return -1;
    }
};
