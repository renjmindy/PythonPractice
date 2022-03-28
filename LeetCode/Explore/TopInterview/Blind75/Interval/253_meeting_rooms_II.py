class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        ap, bp = list(), list()
        
        for interval in intervals:
          ap.append(interval[0])
          bp.append(interval[1])
            
        ap.sort()
        bp.sort()
        
        counter = 0
        l = 0
        
        for r in range(len(intervals)):
          if ap[r] < bp[l]:
            counter += 1
          else:
            l += 1
            
        return counter
