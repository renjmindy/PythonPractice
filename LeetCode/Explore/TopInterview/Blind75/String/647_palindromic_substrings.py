class Solution:
    def countSubstrings(self, s: str) -> int:
      @cache
      def isPalindrome(i, j):
        return i >= j or s[i] == s[j] and isPalindrome(i + 1, j - 1)
      return sum(isPalindrome(i, j) for i in range(len(s)) for j in range(i, len(s)))class Solution:
   
