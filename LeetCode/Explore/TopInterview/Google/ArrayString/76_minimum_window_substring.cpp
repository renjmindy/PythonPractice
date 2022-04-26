class Solution {
public:
    string minWindow(string s, string t) {
      int counter = 0;
      unordered_map<char, int> mp;
      int idx = -1, minLen = INT_MAX;
      string ans = "";
      for (int i = 0; i < t.size(); i++) {
        mp[t[i]]++;
      }
      for (int r = 0, l = 0; r < s.size(); r++) {
        if (mp[s[r]] > 0) {
          counter++;
        }
        mp[s[r]]--;
        if (counter < t.size()) {
          continue;
        }
        while (l < r && mp[s[l]] < 0) {
          mp[s[l]]++;
          l++;
        }
        if (r - l + 1 < minLen) {
          idx = l;
          minLen = r - l + 1;
          ans = s.substr(idx, minLen);
        }
      }
      return ans;
    }
};
