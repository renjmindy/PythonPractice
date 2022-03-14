// two pointers sliding window hash table
// Complexity Analysis
// Time complexity : O(n)O(n). Index jj will iterate nn times.
// Space complexity (HashMap) : O(min(m, n))O(min(m,n)). Same as the previous approach.
// Space complexity (Table): O(m)O(m). mm is the size of the charset.

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() <= 1) {
      return s.size();
    }
    unordered_map<char, int> mp;
    int maxLen = INT_MIN;
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
