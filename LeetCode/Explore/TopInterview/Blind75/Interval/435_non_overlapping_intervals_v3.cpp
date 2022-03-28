class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int counter = 0;
      vector<vector<int> > ans;
      sort(intervals.begin(), intervals.end());
      ans.push_back(intervals[0]);
      for (int i = 1; i < intervals.size(); i++) {
       if (ans.back()[1] > intervals[i][0]) {
         counter++;
         ans.back()[1] = min(ans.back()[1], intervals[i][1]);
       }
       else {
         ans.push_back(intervals[i]);
       } 
      }
      return counter;
    }
};
