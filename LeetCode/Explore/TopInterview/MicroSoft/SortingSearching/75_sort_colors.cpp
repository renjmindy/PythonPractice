class Solution {
public:
    void sortColors(vector<int>& nums) {
      int cur = 0, l = 0, r = nums.size() - 1;
      while (cur <= r) {
        if (nums[cur] == 0) {
          swap(nums[cur], nums[l]);
          cur++;
          l++;
        }
        else if (nums[cur] == 2) {
          swap(nums[cur], nums[r]);
          r--;
        }
        else {
          cur++;
        }
      }
    }
};
