class Solution {
  
private:
  void twoSum(vector<int> &nums, int l, vector<vector<int> > &ans) {
    unordered_set<int> sp;
    for (int r = l + 1; r < nums.size(); r++) {
      int complement = -nums[l]-nums[r];
      if (sp.count(complement)) {
        ans.push_back({nums[l], complement, nums[r]});
        while (r + 1 < nums.size() && nums[r] == nums[r + 1]) {
          r++;
        }
      }
      sp.insert(nums[r]);
    }
  }
  
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;
    for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
      if (i == 0 || nums[i - 1] != nums[i]) {
        twoSum(nums, i, ans);
      }
    }
    return ans;
  }
};
