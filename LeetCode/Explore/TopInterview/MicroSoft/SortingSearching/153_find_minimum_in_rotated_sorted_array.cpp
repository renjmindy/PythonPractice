class Solution {
public:
    int findMin(vector<int>& nums) {
      int pivot, l = 0, r = nums.size() - 1;
      while (l < r) {
        pivot = l + (r - l) / 2;
        if (nums[pivot] < nums[r]) {
          r = pivot;
        }
        else {
          l = pivot + 1;
        }
      }
      return nums[l];
    }
};
