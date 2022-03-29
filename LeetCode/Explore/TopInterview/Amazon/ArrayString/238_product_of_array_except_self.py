class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        mul = 1
        dp = [1] * len(nums)
        
        for i, num in enumerate(nums):
          dp[i] *= mul
          mul *= num
          
        mul = 1  
        for i in range(len(nums) - 1, -1, -1):
          dp[i] *= mul
          mul *= nums[i]
          
        return dp
