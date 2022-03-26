class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
      if len(s) <= 1:
        return len(s)
      
      maxLen = 0
      l = 0
      mp = dict()
      
      for r, c in enumerate(s):
        if c in mp.keys():
          l = max(l, mp[c])
        mp[c] = r + 1
        maxLen = max(maxLen, r - l + 1)
        
      return maxLen
