class Solution:
    def isValid(self, s: str) -> bool:
      mp = {')':'(', '}':'{', ']':'['}
      stack = list()
      
      for c in s:
        if c not in mp:
          stack.append(c)
        else:
          if len(stack) == 0 or mp[c] != stack[-1]:
            return False
          stack.pop()
          
      return len(stack) == 0
