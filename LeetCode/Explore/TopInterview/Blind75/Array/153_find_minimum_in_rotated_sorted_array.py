class Solution:
    def findMin(self, nums: List[int]) -> int:
      l, r = 0, len(nums) - 1
      
      while l < r:
        pivot = l + (r - l) // 2
        if nums[pivot] < nums[r]:
          r = pivot
        else:
          l = pivot + 1
          
      return nums[l]
