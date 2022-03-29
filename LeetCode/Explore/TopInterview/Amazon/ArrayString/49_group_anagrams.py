class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = dict()
        ans = list()
        
        for str in strs:
          tmp = ''.join(sorted(str))
          mp.setdefault(tmp, []).append(str)
          
        for v in mp.values():
          ans.append(v)
          
        return ans
