static bool comp(vector<int>&a,vector<int>&b) {
        return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int> > ans;
        ans.push_back(intervals[0]);
        int count = 0;
        for (int curr = 1, prev = 0; curr < intervals.size(); curr++) {
            if (intervals[curr][0] < ans[prev][1]) {
                count += 1;
            }
            else {
                ans.push_back(intervals[curr]);
                prev++;
            }
        }
        return count;
    }
};
