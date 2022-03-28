class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        ans = list()
        ans.append(intervals[0])
        counter = 0
        
        for i in range(1, len(intervals), 1):
          if ans[-1][1] > intervals[i][0]:
            counter += 1
            ans[-1][1] = min(ans[-1][1], intervals[i][1])
          else:
            ans.append(intervals[i])
            
        return counter
