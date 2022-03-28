class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [0] * len(nums)
        dp[0] = nums[0]
        
        for i in range(1, len(nums), 1):
          if dp[i - 1] < i:
            return False
          dp[i] = max(dp[i - 1], i + nums[i])
          
        return dp[len(nums) - 1] >= len(nums) - 1
