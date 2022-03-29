class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        sp = set()
        
        for word in wordDict:
          sp.add(word)
          
        dp = [False] * (len(s) + 1)
        dp[0] = True
        
        for i in range(1, len(s) + 1, 1):
          for j in range(i):
            if dp[j] and s[j:i] in sp:
              dp[i] = True
              
        return dp[len(s)]
