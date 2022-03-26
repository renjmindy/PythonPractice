class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
      maxLen, counter, l = 0, 0, 0
      mp = dict()
      
      for r, c in enumerate(s):
        mp[c] = mp.get(c, 0) + 1
        counter = max(counter, mp[c])
        if r - l + 1 - counter > k:
          mp[s[l]] -= 1 
          l += 1
        maxLen = max(maxLen, r - l + 1)
      
      return maxLen
