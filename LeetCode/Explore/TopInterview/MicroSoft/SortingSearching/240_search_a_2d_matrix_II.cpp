class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int r = matrix.size() - 1, c = 0;
      while (r >= 0 && c <= matrix[0].size() - 1) {
        if (target < matrix[r][c]) {
          r--;
        }
        else if (target > matrix[r][c]) {
          c++;
        }
        else {
          return true;
        }
      }
      return false;
    }
};
