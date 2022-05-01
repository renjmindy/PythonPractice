class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
      vector<string> ans;
      nums.push_back(upper + 1);
      for (auto num : nums) {
        if (lower < num) {
          ans.push_back(to_string(lower) + ((lower == num - 1) ? "" : "->" + to_string(num - 1)));
        }
        lower = num + 1;
      }
      return ans;
    }
};
