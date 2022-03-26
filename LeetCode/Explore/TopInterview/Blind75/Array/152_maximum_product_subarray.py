class Solution:
    def maxProduct(self, nums: List[int]) -> int:
      maxProd, curMax, curMin = nums[0], nums[0], nums[0]
      for i in nums[1:]:
        tmpMax = max(i, max(i * curMax, i * curMin))
        curMin = min(i, min(i * curMax, i * curMin))
        curMax = tmpMax
        maxProd = max(maxProd, curMax)
        
      return maxProd
