class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      if (nums.size() <= 1) {
        return 0;
      }
      vector<int> nums_clone = nums;
      sort(nums_clone.begin(), nums_clone.end(), greater<int>());
      return nums_clone[0] == nums_clone[1]*2 ? max_element(nums.begin(), nums.end()) - nums.begin() : -1;
    }
};
