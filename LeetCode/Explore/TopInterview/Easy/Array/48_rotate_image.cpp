class Solution {
  
private:
  void transport(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = i + 1; j < matrix[0].size(); j++) {
        int tmp = matrix[i][j];
        swap(matrix[i][j], matrix[j][i]);
        matrix[j][i] = tmp;
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
    transport(matrix);
    reversal(matrix);
  }
};
