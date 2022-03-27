class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
      dp = [False] * (len(s) + 1)
      dp[0] = True
      
      sp = set(wordDict)
      
      for i in range(1, len(s) + 1, 1):
        for j in range(0, i, 1):
          if dp[j] and s[j:i] in sp:
            dp[i] = True
            break
            
      return dp[len(s)]
