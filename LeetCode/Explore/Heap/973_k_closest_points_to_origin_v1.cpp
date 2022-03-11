class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<pair<int, int> > vp;
    vector<vector<int> > ans;
    int i = 0;
    for (auto &point : points) {
      vp.push_back(make_pair(pow(point[0], 2) + pow(point[1], 2), i));
      i++;
    }
    sort(vp.begin(), vp.end());
    for (int j = 0; j < k; j++) {
      ans.push_back(points[vp[j].second]);
    }
    return ans;
  }
};
