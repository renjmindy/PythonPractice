class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<pair<int, int> > vp;
        vector<int> ip;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                vp.push_back(make_pair(pow(points[i][0] - x, 2) + pow(points[i][1] - y, 2), i));
            }
        }
        if (vp.size() > 0) {
            sort(vp.begin(), vp.end());
            ip.push_back(vp[0].second);
            for (int i = 1; i < vp.size(); i++) {
                if (vp[i].first == vp[0].first) {
                    ip.push_back(vp[i].second);
                }
            }
            sort(ip.begin(), ip.end());
            return ip.front();
        }
        else {
            return -1;
        }
    }
};
