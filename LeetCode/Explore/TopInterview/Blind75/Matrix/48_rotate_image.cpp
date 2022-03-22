// Reverse on Diagonal and then Reverse Left to Right

// Complexity Analysis
// Let MM be the number of cells in the grid.
// Time complexity : \mathcal{O}(M)O(M). We perform two steps; transposing the matrix, and then reversing each row. 
// Transposing the matrix has a cost of \mathcal{O}(M)O(M) because we're moving the value of each cell once. 
// Reversing each row also has a cost of \mathcal{O}(M)O(M), because again we're moving the value of each cell once.
// Space complexity : \mathcal{O}(1)O(1) because we do not use any other additional data structures.

class Solution {

private:
  void transpose(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) { 
      for (int j = i + 1; j < matrix[0].size(); j++) { 
        swap(matrix[i][j], matrix[j][i]); 
      }
    }
  }
  
  void reversal(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
  
public:
  void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    reversal(matrix);
  }
};
