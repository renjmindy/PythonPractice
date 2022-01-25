class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = dict()
        ans = list()
        for i, n in enumerate(nums):
            if target - n in mp:
                ans.append(i)
                ans.append(mp[target - n])
            mp[n] = i
                
        return ans
