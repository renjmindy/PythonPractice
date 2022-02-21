class Solution {
public:
    int search(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int pivot, l = 0, r = nums.size() - 1;
      while (l <= r) {
        pivot = l + (r - l) / 2;
        if (nums[pivot] > target) {
          r--;
        }
        else if (nums[pivot] < target) {
          l++;
        }
        else {
          return pivot;
        }
      }
      return -1;
    }
};
