class Solution {

private:
  unordered_map<int, int> mp;
  
public:
  bool containsDuplicate(vector<int>& nums) {
    for (auto &num : nums) {
      mp[num]++;
      if (mp[num] > 1) {
        return true;
      }
    }
    return false;
  }
};
