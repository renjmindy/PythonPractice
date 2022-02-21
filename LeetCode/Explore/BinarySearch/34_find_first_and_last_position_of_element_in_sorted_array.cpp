class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int pivot, l = 0, r = nums.size() - 1;
    bool isFirst = true;
    while (l <= r) {
      pivot = l + (r - l) / 2;
      if (nums[pivot] > target) {
        r = pivot - 1;
      }
      else if (nums[pivot] < target) {
        l = pivot + 1;
      }
      else {
        r = pivot + 1;
        l = pivot - 1;
        while (r < nums.size() && nums[r] == target) {
          r++;
        }
        while (l >=  0 && nums[l] == target) {
          l--;
        }
        return vector<int> {l + 1, r - 1};
      }
    }
    return {-1, -1};
  }
};
