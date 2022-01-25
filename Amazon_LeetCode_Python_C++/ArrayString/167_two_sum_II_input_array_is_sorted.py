class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        ans = list()
        mp = dict()
        for i, n in enumerate(numbers):
            if target - n in mp:
                ans.append(mp[target - n])
                ans.append(i + 1)
            mp[n] = i + 1
        return ans
