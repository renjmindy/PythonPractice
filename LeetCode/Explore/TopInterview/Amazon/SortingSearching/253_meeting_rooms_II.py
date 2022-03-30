class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        ap, bp = list(), list()
        for interval in intervals:
          ap.append(interval[0])
          bp.append(interval[1])
          
        ap.sort()
        bp.sort()
        j = 0
        counter = 0
        
        for i in range(len(intervals)):
          if ap[i] < bp[j]:
            counter += 1
          else:
            j += 1
            
        return counter
