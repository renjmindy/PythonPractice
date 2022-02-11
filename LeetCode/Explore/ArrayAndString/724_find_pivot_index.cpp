class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++) {
        if (accumulate(nums.begin(), nums.begin() + i, 0) == accumulate(nums.begin() + i + 1, nums.end(), 0)) {
          return i;
        }
      }
      return -1;
    }
};
