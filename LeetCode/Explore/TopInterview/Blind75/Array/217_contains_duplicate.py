class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
      s = list()
      
      for i, num in enumerate(nums):
        s.append(num)
        
      return len(list(set(s))) < len(s)
