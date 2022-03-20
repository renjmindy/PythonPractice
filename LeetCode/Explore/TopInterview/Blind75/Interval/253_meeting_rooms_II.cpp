// Chronological Ordering

// Complexity Analysis
// Time Complexity: O(N\log N)O(NlogN) because all we are doing is sorting the two arrays for start timings and end timings individually 
// and each of them would contain NN elements considering there are NN intervals.
// Space Complexity: O(N)O(N) because we create two separate arrays of size NN, one for recording the start times and one for the end times.

class Solution {
  
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    int ans = 0;
    vector<int> a, b;
    for (auto &interval : intervals) {
      a.push_back(interval[0]);
      b.push_back(interval[1]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0, j = 0; i < a.size(); i++) {
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
