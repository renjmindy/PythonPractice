class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minCost = prices[0]
        maxGain = 0
        
        for i in range(1, len(prices), 1):
          if prices[i] < minCost:
            minCost = prices[i]
          else:
            maxGain = max(maxGain, prices[i] - minCost)
            
        return maxGain
