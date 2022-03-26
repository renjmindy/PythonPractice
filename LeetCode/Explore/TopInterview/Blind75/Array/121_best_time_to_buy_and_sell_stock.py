class Solution:
    def maxProfit(self, prices: List[int]) -> int:
      minCost = prices[0]
      maxGain = 0
      
      for i, price in enumerate(prices):
        if price < minCost:
          minCost = min(minCost, price)
        elif price > minCost:
          maxGain = max(maxGain, price - minCost)
        else:
          continue
          
      return maxGain
