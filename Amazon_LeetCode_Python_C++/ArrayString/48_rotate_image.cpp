class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        tra(matrix);
        rev(matrix);
    }
    
public:
    void tra(vector<vector<int> >& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
    
public:
    void rev(vector<vector<int> >& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size() / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - 1 - j];
                matrix[i][matrix.size() - 1 - j] = tmp;
            }
        }
    }
};
