class Solution {
public:
  int search(vector<int>& nums, int target) {
    int pivot, l = 0, r = nums.size() - 1;
    while (l <= r) { // overlapped
      pivot = l + (r - l) / 2;
      if (nums[pivot] == target) {
        return pivot;
      }
      if (nums[l] <= nums[pivot]) { // low-high-high
        if (target >= nums[l] && target < nums[pivot]) { // left-mid
          r = pivot - 1;
        }
        else {
          l = pivot + 1;
        }
      }
      else { // high-low-high 
        if (target <= nums[r] && target > nums[pivot]) { // mid-right  
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
