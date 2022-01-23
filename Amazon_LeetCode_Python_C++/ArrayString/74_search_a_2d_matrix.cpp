class Solution {

public: 
    bool bs(vector<vector<int>>& matrix, int target, int start, bool vertical) {
        int l = start;
        int h = vertical ? matrix[0].size() - 1 : matrix.size() - 1;
        
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (vertical) {
                if (matrix[start][m] < target) {
                    l = m + 1;
                }
                else if (matrix[start][m] > target) {
                    h = m - 1;
                }
                else {
                    return true;
                }
            }
            else {
                if (matrix[m][start] < target) {
                    l = m + 1;
                }
                else if (matrix[m][start] > target) {
                    h = m - 1;
                }
                else {
                    return true;
                }
            }
        }
        return false;
}
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int sDim = min(matrix.size(), matrix[0].size());
        for (int i = 0; i < sDim; i++) {
            bool vFound = bs(matrix, target, i, true);
            bool hFound = bs(matrix, target, i, false);
            if (vFound || hFound) {
                return true;
            }
        }
        return false;
    }
};
