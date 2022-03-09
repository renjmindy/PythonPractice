class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> sp;
    for (int i = 0; i < nums.size(); i++) {
      if (sp.count(nums[i])) {
        return true;
      }
      sp.insert(nums[i]);
      if (sp.size() > k) {
        sp.erase(nums[i - k]);
      }
    }
    return false;
  }
};
