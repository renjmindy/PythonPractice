class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> start, end;
    for (auto &interval : intervals) {
      start.push_back(interval[0]);
      end.push_back(interval[1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int counter = 0;
    for (int l = 0, r = 0; l < intervals.size(); l++) {
      if (start[l] < end[r]) { // start time earlier than end time --> plus one room 
        counter++;
      } 
      else {
        r++;
      }
    }
    return counter;
  }
};
