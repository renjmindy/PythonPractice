class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
          return False
        
        mp = Counter(s)
        
        for c in t:
          if c in mp and mp[c] > 0:
            mp[c] -= 1
          else:
            return False
          
        return True
