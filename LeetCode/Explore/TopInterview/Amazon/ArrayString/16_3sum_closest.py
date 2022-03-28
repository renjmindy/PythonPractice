class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        minDiff = 1000000
        nums.sort()
        
        for i in range(len(nums)):
          if minDiff != 0:
            l = i + 1
            r = len(nums) - 1
            while l < r:
              sum = nums[i] + nums[l] + nums[r]
              if abs(target - sum) < abs(minDiff):
                minDiff = target - sum
              if sum < target:
                l += 1
              else:
                r -= 1
              
        return target - minDiff
