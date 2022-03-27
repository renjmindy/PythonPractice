class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
          return 0
        if len(nums) == 1:
          return nums[0]
        
        dp = [0] * len(nums)
        dp[len(nums) - 1] = nums[len(nums) - 1]
        dp[len(nums) - 2] = max(nums[len(nums) - 1], nums[len(nums) - 2])
        
        for i in range(len(nums) - 3, 0, -1):
          dp[i] = max(dp[i + 1], dp[i + 2] + nums[i])
        
        tmp1 = dp[1]
        
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, len(nums) - 1, 1):
          dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
          
        tmp2 = dp[len(nums) - 2]
        
        return max(tmp1, tmp2)
          
        
