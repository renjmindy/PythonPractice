class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      if (s.size() <= k) {
        return s.size();
      } 
      unordered_map<char, int> mp;
      int maxLen = k;
      for (int r = 0, l = 0; r < s.size(); r++) {
        mp[s[r]] = r;
        if (mp.size() == k + 1) {
          int idx = s.size() - 1;
          for (auto &m : mp) {
            idx = min(idx, m.second);
          }
          mp.erase(s[idx]);
          l = idx + 1;
        }
        maxLen = max(maxLen, r - l + 1);
      }
      return maxLen;
    }
};
