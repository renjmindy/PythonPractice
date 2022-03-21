// Additional Memory Approach

// Complexity Analysis
// Time Complexity: O(M \times N)O(M×N) where M and N are the number of rows and columns respectively.
// Space Complexity: O(M + N)O(M+N).

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    set<int> vr, vc;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          if (!vr.count(i)) {
            vr.insert(i);
          }
          if (!vc.count(j)) {
            vc.insert(j);
          }
        }
      }
    }
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (vr.count(i) || vc.count(j)) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
