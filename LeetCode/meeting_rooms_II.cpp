static bool comp (vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> s;
        vector<int> e;
        for (auto i : intervals) {
            s.push_back(i[0]);
            e.push_back(i[1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        int fin = 0, count = 0;
        for (int ini = 0; ini < intervals.size(); ini++) {
            if (s[ini] < e[fin]) {
                count += 1;
            }
            else {
                fin++;
            }
        }
        return count;
    }
};
