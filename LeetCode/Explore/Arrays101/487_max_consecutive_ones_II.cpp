class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int count = 0, maxVal = INT_MIN;
      for (int r = 0, l = 0; r < nums.size(); r++) {
        if (nums[r] == 0) {
          count++;
        }
        while (count == 2) {
          if (nums[l] == 0) {
            count--;
          }
          l++;
        }
        maxVal = max(maxVal, r - l + 1);
      }
      return maxVal;
    }
};
