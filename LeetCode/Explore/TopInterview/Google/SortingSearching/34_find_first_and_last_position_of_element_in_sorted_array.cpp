class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int pivot, l = 0, r = nums.size() - 1;
      while (l <= r) {
        pivot = l + (r - l) / 2;
        if (nums[pivot] < target) {
          l = pivot + 1;
        }
        else if (nums[pivot] > target) {
          r = pivot - 1;
        }
        else {
          l = pivot;
          r = pivot;
          while (r < nums.size() && nums[r] == target) {
            r++;
          }
          while (l >= 0 && nums[l] == target) {
            l--;
          }
          return {l + 1, r - 1};
        }
      } 
      return {-1, -1};
    }
};
