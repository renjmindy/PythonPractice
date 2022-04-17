class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char, int> mp;
      int minLen = INT_MAX, idx = -1, l = 0, count = 0;
      string ans = "";
      for (auto &c : t) {
        mp[c]++;
      }
      for (int r = 0; r < s.size(); r++) {
        if (mp[s[r]] > 0) {
          count++;
        }
        mp[s[r]]--;
        if (count < t.size()) {
          continue;
        }
        while (l < r && mp[s[l]] < 0) {
          mp[s[l]]++;
          l++;
        }
        if (ans.empty() || r - l + 1 < minLen) {
          idx = l;
          minLen = r - l + 1;
          ans = s.substr(idx, minLen);
        }
      }
      return ans;
    }
};
