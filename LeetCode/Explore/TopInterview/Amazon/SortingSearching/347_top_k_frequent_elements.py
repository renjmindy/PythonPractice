class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = dict()
        
        for num in nums:
          mp[num] = mp.get(num, 0) + 1
        
        sp = [k for k, v in sorted(mp.items(), key = lambda x:x[1], reverse=True)]
        
        return sp[:k]
