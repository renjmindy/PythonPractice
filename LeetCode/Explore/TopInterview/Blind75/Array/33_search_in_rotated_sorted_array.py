class Solution:
    def search(self, nums: List[int], target: int) -> int:
      l, r = 0, len(nums) - 1
      
      while l <= r:
        pivot = l + (r - l) // 2
        if nums[pivot] == target:
          return pivot
        elif nums[l] <= nums[pivot]:
          if target >= nums[l] and target < nums[pivot]:
            r = pivot - 1
          else:
            l = pivot + 1
        else:
          if target > nums[pivot] and target <= nums[r]:
            l = pivot + 1
          else:
            r = pivot - 1
            
      return -1
