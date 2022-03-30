class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        mp = dict()
        vp = list()
        
        for i, num in enumerate(numbers):
          if target - num in mp:
            vp.append(mp[target - num])
            vp.append(i + 1)
          mp[num] = i + 1
          
        return vp
