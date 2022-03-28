class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int maxLen = INT_MIN;
      unordered_map<char, int> mp;
      for (int r = 0, l = 0; r < s.size(); r++) {
        if (mp.count(s[r])) {
          l = max(l, mp[s[r]]);
        }
        mp[s[r]] = r + 1;
        maxLen = max(maxLen, r - l + 1);
      }
      return maxLen > INT_MIN ? maxLen : 0;
    }
};
