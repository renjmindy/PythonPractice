class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [1 for i in range(len(nums))]
        mul = 1
        
        for i, num in enumerate(nums):
            ans[i] *= mul
            mul *= num
            
        mul = 1    
        for i in range(len(nums) - 1, -1, -1):
            ans[i] *= mul
            mul *= nums[i]
            
        return ans
