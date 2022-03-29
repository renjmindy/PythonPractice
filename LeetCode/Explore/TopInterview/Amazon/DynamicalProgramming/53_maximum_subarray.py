class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
      curVal, maxSum = nums[0], nums[0]
      
      for i in range(1, len(nums), 1):
        curVal = max(nums[i], curVal + nums[i])
        maxSum = max(maxSum, curVal)
        
      return maxSum
