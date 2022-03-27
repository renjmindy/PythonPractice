class Solution:
    def isPalindrome(self, s: str) -> bool:
      t = list()
      for c in s:
        if c.isalnum():
          t.append(c.lower())
          
      return t == t[::-1]
