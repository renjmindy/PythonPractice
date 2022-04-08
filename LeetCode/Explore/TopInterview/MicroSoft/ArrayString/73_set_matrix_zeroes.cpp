class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      set<int> rp, cp;
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
          if (matrix[i][j] == 0) {
            if (!rp.count(i)) rp.insert(i);
            if (!cp.count(j)) cp.insert(j);
          }
        }
      }
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
          if (rp.count(i) || cp.count(j)) {
            matrix[i][j] = 0;
          }
        }
      }
    }
};
