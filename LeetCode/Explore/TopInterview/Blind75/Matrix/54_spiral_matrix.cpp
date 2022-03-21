// Set Up Boundaries

// Complexity Analysis
// Let MM be the number of rows and NN be the number of columns.
// Time complexity: O(M \cdot N)O(M⋅N). This is because we visit each element once.
// Space complexity: O(1)O(1). This is because we don't use other data structures. Remember that we don't include the output array in the space complexity.

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int u = 0, l = 0, d = matrix.size() - 1, r = matrix[0].size() - 1;
    
    while (ans.size() < matrix[0].size() * matrix.size()) {
      
      // traverse from left to right
      for (int j = l; j <= r; j++) {
        ans.push_back(matrix[u][j]);
      }
    
      // traverse from upside down
      for (int i = u + 1; i <= d; i++) {
        ans.push_back(matrix[i][r]);
      }
    
      // make sure we are now on a different row
      if (u != d) {
        // traverse from right to left
        for (int j = r - 1; j >= l; j--) {
          ans.push_back(matrix[d][j]);
        }
      }
    
      // make sure we are on a different column
      if (l != r) {
        // traverse from downside up
        for (int i = d - 1; i > u; i--) {
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
