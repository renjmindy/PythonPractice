class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
      if len(intervals) == 0:
        return True
      
      intervals.sort()
      
      for i in range(0, len(intervals) - 1, 1):
        if intervals[i][1] > intervals[i + 1][0]:
          return False
        
      return True
