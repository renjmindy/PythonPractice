class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      unordered_map<int, int> mp;
      vector<int> vp;
      for (int i = 0; i < numbers.size(); i++) {
        if (mp.count(target - numbers[i])) {
          vp.push_back(mp[target - numbers[i]]);
          vp.push_back(i + 1);
        }
        mp[numbers[i]] = i + 1;
      }
      return vp;
    }
};
