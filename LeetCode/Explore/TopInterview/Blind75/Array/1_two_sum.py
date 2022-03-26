class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
      ans = list()
      mp = dict()
      
      for i, num in enumerate(nums):
        if target - num in mp.keys():
          ans.append(mp[target - num])
          ans.append(i)
          
        mp[nums[i]] = i
        
      return ans
