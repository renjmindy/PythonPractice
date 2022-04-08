class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
      vector<int> ans;
      while (ans.size() < matrix.size() * matrix[0].size()) {
        for (int i = l; i <= r; i++) {
          ans.push_back(matrix[u][i]);
        }
        for (int i = u + 1; i <= d; i++) {
          ans.push_back(matrix[i][r]);
        }
        if (u != d) {
          for (int i = r - 1; i >= l; i--) {
            ans.push_back(matrix[d][i]);
          }
        }
        if (l != r) {
          for (int i = d - 1; i >= u + 1; i--) {
            ans.push_back(matrix[i][l]);
          }
        }
        l++;
        r--;
        u++;
        d--;
      }
      return ans;
    }
};
