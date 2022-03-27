class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [1000000] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1, 1):
          for coin in coins:
            if coin <= i and dp[i - coin] < 1000:
              dp[i] = min(dp[i], dp[i - coin] + 1)
              
        if dp[amount] <= amount:
          return dp[amount]
        else:
          return -1
