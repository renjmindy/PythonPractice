class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int> > vp;
        vector<vector<int> > ans;
        for (int i = 0; i < points.size(); i++) {
            vp.push_back(make_pair(pow(points[i][0], 2) + pow(points[i][1], 2), i));
        }
        sort(vp.begin(), vp.end());
        for (int i = 0; i < k; i++) {
            ans.push_back(points[vp[i].second]);
        }
        return ans;
    }
};
