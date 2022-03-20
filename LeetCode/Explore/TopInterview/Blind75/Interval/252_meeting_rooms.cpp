// Sorting

// Complexity Analysis
// Time complexity : O(n \log n)O(nlogn). The time complexity is dominated by sorting. 
// Once the array has been sorted, only O(n)O(n) time is taken to go through the array and determine if there is any overlap.
// Space complexity : O(1)O(1). Since no additional space is allocated.

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1][1] > intervals[i][0]) {
        return false;
      } 
    }
    return true;
  }
};
