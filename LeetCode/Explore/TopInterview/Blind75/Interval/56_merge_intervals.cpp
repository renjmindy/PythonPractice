// Sorting

// Complexity Analysis
// Time complexity : O(n\log{}n)O(nlogn)
// Other than the sort invocation, we do a simple linear scan of the list, so the runtime is dominated by the O(n\log{}n)O(nlogn) complexity of sorting.
// Space complexity : O(\log N)O(logN) (or O(n)O(n))
// If we can sort intervals in place, we do not need more than constant additional space, although the sorting itself takes O(\log n)O(logn) space. 
// Otherwise, we must allocate linear space to store a copy of intervals and sort that.

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int> > ans;
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (int i = 1, j = 0; i < intervals.size(); i++) {
      if (intervals[i][0] > ans.back()[1]) {
        ans.push_back(intervals[i]);
        j++;
      }
      else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }
    return ans;
  }
};

//

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int> > ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++) {
      if (ans.empty() || intervals[i][0] > ans.back()[1]) {
        ans.push_back(intervals[i]);
      }
      else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }
    return ans;
  }
};
