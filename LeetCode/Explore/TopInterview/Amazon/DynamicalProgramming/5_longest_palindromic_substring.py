class Solution:
    def longestPalindrome(self, s: str) -> str:
        dp = [[False] * len(s) for i in range(len(s))]
        idx = -1
        maxLen = -1
        
        for r in range(len(s)):
          for l in range(r, -1, -1):
            if r == l:
              dp[l][r] = True
            elif r - l == 1:
              dp[l][r] = (s[l] == s[r])
            else:
              dp[l][r] = dp[l + 1][r - 1] and (s[l] == s[r])
            if dp[l][r] and r - l + 1 > maxLen:
              idx = l
              maxLen = r - l + 1
              
        return s[idx:idx + maxLen]
        
