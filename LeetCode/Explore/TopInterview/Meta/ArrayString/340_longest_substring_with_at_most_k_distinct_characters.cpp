class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      int maxLen = k;
      unordered_map<char, int> mp;
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
