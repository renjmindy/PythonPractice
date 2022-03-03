class Solution {
  
private:
  void twoSum(vector<int> &nums, int i, vector<vector<int> > &ans) {
    int l = i + 1, r = nums.size() - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum < 0) {
        l++;
      }
      else if (sum > 0) {
        r--;
      }
      else {
        ans.push_back({nums[i], nums[l], nums[r]});
        l++;
        r--;
        while (l < r && nums[l - 1] == nums[l]) {
          l++;
        }
      }
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
