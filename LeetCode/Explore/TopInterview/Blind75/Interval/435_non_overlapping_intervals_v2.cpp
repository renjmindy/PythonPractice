class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      int counter = 0, maxEnd = intervals[0][1];
      for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < maxEnd) {
          counter++;
          maxEnd = min(maxEnd, intervals[i][1]);
        }
        else {
          maxEnd = intervals[i][1];
        }
      }
      return counter;
    }
};
