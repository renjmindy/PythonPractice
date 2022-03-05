class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    /*int pivot, l = 0, r = nums.size() - 1;
    while (l < r) {
      pivot = l + (r - l) / 2;
      if (nums[pivot] < nums[pivot + 1]) {
        l = pivot + 1;
      }
      else {
        r = pivot;
      }
    }
    return nums[l] <= nums[r] ? r : l;*/
    return max_element(nums.begin(), nums.end()) - nums.begin();
  }
};
