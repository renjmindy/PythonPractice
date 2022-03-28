class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = dict()
        maxLen = 0
        l = 0
        
        for r, c in enumerate(s):
          if c in mp:
            l = max(l, mp[c])
          mp[c] = r + 1
          maxLen = max(maxLen, r - l + 1)
          
        return maxLen
