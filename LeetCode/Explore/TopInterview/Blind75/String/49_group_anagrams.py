class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
      mp = dict()
      ans = list()
      
      for str in strs:
        tmp = sorted(str)
        mp.setdefault(''.join(tmp), []).append(str)
        
      for v in mp.values():
        ans.append(v)
        
      return ans
