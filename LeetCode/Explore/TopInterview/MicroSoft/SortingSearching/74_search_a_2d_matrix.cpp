class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.size() == 0) {
        return false;
      }
      int l = 0, r = (matrix.size() * matrix[0].size()) - 1;
      int pivotIdx, pivotVal;
      while (l <= r) {
        pivotIdx = l + (r - l) / 2;
        pivotVal = matrix[pivotIdx / matrix[0].size()][pivotIdx % matrix[0].size()];
        if (target == pivotVal) {
          return true;
        }
        else {
          if (target < pivotVal) {
            r = pivotIdx - 1;
          }
          else {
            l = pivotIdx + 1;
          }
        }
      }
      return false;
    }
};
