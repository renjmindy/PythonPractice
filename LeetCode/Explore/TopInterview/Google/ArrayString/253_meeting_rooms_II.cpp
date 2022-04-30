class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      int ans = 0;
      vector<int> a, b;
      //sort(intervals.begin(), intervals.end());
      for (auto &interval : intervals) {
        a.push_back(interval[0]);
        b.push_back(interval[1]);
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      for (int i = 0, j = 0; i < intervals.size(); i++) {
        //if (intervals[i - 1][1] > intervals[i][0]) {
        //ans++;
        //}
        if (a[i] < b[j]) {
          ans++;
        }
        else {
          j++;
        }
      }
      return ans;
    }
};
