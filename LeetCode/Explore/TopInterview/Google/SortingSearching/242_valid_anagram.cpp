class Solution {
public:
    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) {
        return false;
      }
      unordered_map<char, int> mp;
      for (auto &c : s) {
        mp[c]++;
      }
      for (auto &c : t) {
        if (mp.count(c) && mp[c] > 0) {
          mp[c]--;
        }
        else {
          return false;
        }
      }
      return true;
    }
};
