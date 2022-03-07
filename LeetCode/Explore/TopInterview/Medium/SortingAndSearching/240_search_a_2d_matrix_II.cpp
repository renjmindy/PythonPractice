class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = matrix.size() - 1, c = 0;
    while (r >= 0 && c < matrix[0].size()) {
      if (matrix[r][c] > target) {
        r--;
      }
      else if (matrix[r][c] < target) {
        c++;
      }
      else {
        return true;
      }
    }
    return false;
  }
};
