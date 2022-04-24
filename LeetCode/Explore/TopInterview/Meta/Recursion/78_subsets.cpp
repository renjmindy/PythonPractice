class Solution {
  
private:
  vector<int> ds;
  vector<vector<int> > ans;
  void helper(int i, vector<int> &nums, vector<int> &ds, vector<vector<int> > &ans) {
    if (i == nums.size()) {
      ans.push_back(ds);
      return;
    }
    //picking the current index in subset combination
    ds.push_back(nums[i]);
    //unique elements and we can't have duplicate subsets so idx+1
    helper(i + 1, nums, ds, ans);
    //not picking the current index in subset combination
    ds.pop_back();
    //moving to next index by not picking so idx+1
    helper(i + 1, nums, ds, ans);
  }
  
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      helper(0, nums, ds, ans);
      return ans;
    }
};
