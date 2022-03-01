class Solution {
public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto &num : nums) {
      mp[num]++;
    }
    for (auto &m : mp) {
      if (m.second == 1) {
        return m.first;
      }
    }
    return -1;
  }
};
