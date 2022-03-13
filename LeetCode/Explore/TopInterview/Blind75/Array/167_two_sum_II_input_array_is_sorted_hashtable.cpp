// one pass hash table
// O(n) time, O(n)O(n) space using hash table

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < numbers.size(); i++) {
      if (mp.count(target - numbers[i])) {
        ans.push_back(mp[target - numbers[i]]);
        ans.push_back(i + 1);
      }
      mp[numbers[i]] = i + 1;
    }
    return ans;
  }
};
