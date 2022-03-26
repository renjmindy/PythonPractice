class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
      maxSum, curVal = nums[0], nums[0]
      for i in nums[1:]:
        curVal = max(i, i + curVal)
        maxSum = max(maxSum, curVal)
        
      return maxSum
    
