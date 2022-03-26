class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
      ans = [1 for i in range(0, len(nums), 1)]
      mul = 1
    
      for i, num in enumerate(nums):
        ans[i] *= mul
        mul *= nums[i]
        
      mul = 1
      for i in range(len(nums) - 1, -1, -1):
        ans[i] *= mul
        mul *= nums[i]
        
      return ans
