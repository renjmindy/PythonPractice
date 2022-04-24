class Solution {
  
private:
  vector<vector<int> > ans;
  void helper(int i, vector<int> &nums, vector<vector<int> > &ans) {
    if (i == nums.size()) {
      ans.push_back(nums);
      return;
    }
    unordered_map<int, int> mp;
    for (int j = i; j < nums.size(); j++) {
      if (!mp[nums[j]]) {
        swap(nums[i], nums[j]);
        helper(i + 1, nums, ans);
        swap(nums[i], nums[j]);
        mp[nums[j]]++;
      }
    }
    return;
  }
  
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      helper(0, nums, ans);
      return ans;
    }
};
