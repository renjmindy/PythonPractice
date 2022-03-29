class Solution {
public:
    string minWindow(string s, string t) {
      string ans;
      int counter = 0, idx = 0, minLen = INT_MAX;
      unordered_map<char, int> mp;
      for (auto &c : t) {
        mp[c]++;
      }
      for (int r = 0, l = 0; r < s.size() && l < s.size(); r++) {
        if (mp[s[r]] > 0) {
          counter++;
        }
        mp[s[r]]--;
        if (counter < t.size()) {
          continue;
        }
        while (l < s.size() && mp[s[l]] < 0) {
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
