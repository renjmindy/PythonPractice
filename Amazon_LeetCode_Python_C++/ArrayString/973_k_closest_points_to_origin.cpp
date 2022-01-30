class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {return squaredDistance(a) < squaredDistance(b);});
        return vector<vector<int> >(points.begin(), points.begin() + k);
    }
    
    int squaredDistance(vector<int> &p) {
        return pow(p[0], 2) + pow(p[1], 2);
    }
};
