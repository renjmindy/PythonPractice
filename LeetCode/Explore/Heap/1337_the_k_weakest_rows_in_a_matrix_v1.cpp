class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int, int> > vp;
    vector<int> ans;
    for (int i = 0; i < mat.size(); i++) {
      int sum = 0;
      for (int j = 0; j < mat[0].size(); j++) {
        sum += mat[i][j];
      }
      vp.push_back(make_pair(sum, i));
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < k; i++) {
      ans.push_back(vp[i].second);
    }
    return ans;
  }
};
