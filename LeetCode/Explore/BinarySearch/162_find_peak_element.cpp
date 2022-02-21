class Solution {
  
private:
  int search(vector<int> &nums, int l, int r) {
    if (l == r) {
      return l;
    }
    int pivot = l + (r - l) / 2;
    if (nums[pivot] < nums[pivot + 1]) {
      return search(nums, pivot + 1, r);
    }
    else {
      return search(nums, l, pivot);
    }
  }
  
public:
  int findPeakElement(vector<int>& nums) {
    return search(nums, 0, nums.size() - 1);
  }
};
