class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int l = 0;
      for (int r = 0; r < nums.size(); r++) {
        if (!nums.at(r)) {
          l = r + 1;
          while (l < nums.size()) {
            if (nums.at(l)) {
              nums[r] = nums[l];
              nums[l] = 0;
              l++;
              break;
            }
            l++;
          }
        }
      }
    }
};
