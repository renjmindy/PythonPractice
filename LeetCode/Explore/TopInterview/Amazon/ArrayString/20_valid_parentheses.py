class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')':'(', '}':'{', ']':'['}
        sp = list()
        
        for i, c in enumerate(s):
          if c not in mp.keys():
            sp.append(c)
          else:
            if len(sp) == 0 or sp[-1] != mp[c]:
              return False
            sp.pop(-1)
            
        return len(sp) == 0
