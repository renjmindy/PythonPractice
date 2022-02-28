class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    unordered_map<int, int> mp;
    for (int r = 0, l = 0; r < s.size(); r++) {
      if (mp.count(s[r])) {
        l = max(l, mp[s[r]]);
      }
      maxLen = max(maxLen, r - l + 1);
      mp[s[r]] = r + 1;
    }
    return maxLen;
  }
};
