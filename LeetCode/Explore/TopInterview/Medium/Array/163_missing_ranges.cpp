class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ans;
    nums.push_back(upper + 1);
    for (int i = 0; i < nums.size(); i++) {
      if (lower < nums[i]) {
        ans.push_back(to_string(lower) + (lower == nums[i] - 1 ? "" : "->" + to_string(nums[i] - 1)));
      }
      lower = nums[i] + 1;
    }
    return ans;
  }
};
