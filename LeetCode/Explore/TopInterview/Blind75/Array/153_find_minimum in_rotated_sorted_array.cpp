// one pass binary search
// Complexity Analysis
// Time Complexity : Same as Binary Search O(\log N)O(logN)
// Space Complexity : O(1)O(1)

class Solution {
public:
  int findMin(vector<int>& nums) {
    int pivot, l = 0, r = nums.size() - 1;
    while (l < r) {
      pivot = l + (r - l) / 2;
      if (nums[pivot] > nums[r]) {
        l = pivot + 1;
      }
      else {
        r = pivot;
      }
    }
    return nums[l];
  }
};
