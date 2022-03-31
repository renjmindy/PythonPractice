class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        mp = dict()
        
        for i, point in enumerate(points):
          mp[i] = point[0] * point[0] + point[1] * point[1]
          
        vp = list(k for k, v in sorted(mp.items(), key = lambda x:x[1]))[:k]
        
        ans = list()
        
        for v in vp:
          ans.append([points[v][0], points[v][1]])
          
        return ans
          
