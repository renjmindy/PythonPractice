class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      int counter = 0;
      vector<int> ap, bp;
      for (auto &interval : intervals) {
        ap.push_back(interval[0]);
        bp.push_back(interval[1]);
      }
      sort(ap.begin(), ap.end());
      sort(bp.begin(), bp.end());
      for (int i = 0, j = 0; i < intervals.size(); i++) {
        if (ap[i] < bp[j]) {
          counter++;
        }
        else {
          j++;
        }
      }
      return counter;
    }
};
