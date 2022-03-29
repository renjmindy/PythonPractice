class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        mp = Counter(t)
        
        l = 0
        counter = 0
        ans = ""
        
        for r, c in enumerate(s):
          if mp[c] > 0:
            counter += 1
          
          mp[c] -= 1
          if counter < len(t):
            continue
            
          while l < len(s) and mp[s[l]] < 0:
            mp[s[l]] += 1
            l += 1
            
          if len(ans) == 0 or r - l + 1 < len(ans):
            ans = s[l : r + 1]
            
        return ans
