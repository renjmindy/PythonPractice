class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ans;
        ans.push_back(intervals[0]);
        for (int curr = 1, prev = 0; curr < intervals.size(); curr++) {
            if (ans[prev][1] >= intervals[curr][0]) {
                ans[prev][1] = max(ans[prev][1], intervals[curr][1]);
            }
            else {
                ans.push_back(intervals[curr]);
                prev++;
            }
        }
        return ans;
    }
};
