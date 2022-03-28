class Solution:
  
    def twoSum(self, nums: List[int], i: int, ans: List[List[int]]):
      l = i + 1
      r = len(nums) - 1
      
      while l < r:
        sum = nums[i] + nums[l] + nums[r]
        if sum < 0:
          l += 1
        elif sum > 0:
          r -= 1
        else:
          ans.append([nums[i], nums[l], nums[r]])
          l += 1
          r -= 1
          while (l < r and nums[l - 1] == nums[l]):
            l += 1
  
    def threeSum(self, nums: List[int]) -> List[List[int]]:
      ans = list()
      nums.sort()
      for i in range(0, len(nums), 1):
        if nums[i] <= 0:
          if len(ans) == 0 or nums[i - 1] != nums[i]:
            self.twoSum(nums, i, ans)
            
      return ans
