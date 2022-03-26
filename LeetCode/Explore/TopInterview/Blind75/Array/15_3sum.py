class Solution:
          
  def threeSum(self, nums: List[int]) -> List[List[int]]:
    nums.sort()
    ans = []
    for i in range(len(nums)):
      if nums[i] > 0:
        break
      if i == 0 or nums[i - 1] != nums[i]:
        self.twoSum(nums, i, ans)
            
    return ans
  
  def twoSum(self, nums: List[int], i: int, ans: List[List[int]]):
    l, r = i + 1, len(nums) - 1
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
        while l < r and nums[l - 1] == nums[l]:
          l += 1
