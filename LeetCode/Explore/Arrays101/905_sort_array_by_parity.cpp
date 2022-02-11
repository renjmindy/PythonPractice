class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      int l = 0;
      for (int r = 0; r < nums.size(); r++) {
        if (nums[r] % 2) {
          l = r + 1;
          while (l < nums.size()) {
            if (!(nums[l] % 2)) {
              swap(nums[r], nums[l]);
              l++;
              break;
            }
            l++;
          }
        }
      }
      return nums;
    }
};
