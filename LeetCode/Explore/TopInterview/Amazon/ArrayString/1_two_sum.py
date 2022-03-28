class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
      mp = dict()
      ans = list()
      
      for i, num in enumerate(nums):
        if target - num in mp:
          ans.append(mp[target - num])
          ans.append(i)
          
        mp[num] = i
          
      return ans
