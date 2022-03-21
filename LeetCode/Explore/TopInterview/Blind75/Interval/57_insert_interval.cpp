// Greedy

// Complexity Analysis
// Time complexity : \mathcal{O}(N)O(N) since it's one pass along the input array.
// Space complexity : \mathcal{O}(N)O(N) to keep the output.

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int> > ans;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (int i = 1, j = 0; i < intervals.size(); i++) {
      if (ans.empty() || intervals[i][0] > ans.back()[1]) {
        ans.push_back(intervals[i]);
        j++; // w/o overlapp, move to next 
      }
      else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }
    return ans;
  }
};
