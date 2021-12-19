static bool comp(vector<int>&a,vector<int>&b) {
        return a[1]<b[1];
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return true;
        }
        sort(intervals.begin(), intervals.end());
        int count = 0;
        vector<vector<int> > ans;
        ans.push_back(intervals[0]);
        for (int curr = 1, prev = 0; curr < intervals.size(); curr++) {
            if (ans[prev][1] > intervals[curr][0]) {
                count += 1;
            }
            else {
                ans.push_back(intervals[curr]);
                prev++;
            }
        }
        return count == 0;
    }
};
