// Using Greedy Approach based on end points

// Complexity Analysis
// Time complexity : O\big(n \log(n)\big)O(nlog(n)). Sorting takes O\big(n \log(n)\big)O(nlog(n)) time.
// Space complexity : O(1)O(1). No extra space is used.

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int ans = 0;
    sort(intervals.begin(), intervals.end());
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < end) {
        ans++;
        end = min(end, intervals[i][1]);
      }
      else {
        end = intervals[i][1];
      }
    }
    return ans;
  }
};

// alternative:

static bool comp(vector<int>&a, vector<int>&b) {
        return a[1] < b[1];
}
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    vector<vector<int> > ans;
    int count = 0;
    sort(intervals.begin(), intervals.end(), comp);
    ans.push_back(intervals[0]);
    for (int i = 1, j = 0; i < intervals.size(); i++) {
      if (intervals[i][0] < ans[j][1]) {
        count++;
      }
      else {
        ans.push_back(intervals[i]);
        j++;
      }
    }
    return count;
  }
};
