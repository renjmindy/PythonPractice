class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int u = 0, l = 0, d = matrix.size() - 1, r = matrix[0].size() - 1;
        
        while (ans.size() < matrix.size() * matrix[0].size()) {
            for (int col = l; col <= r; col++) {
                ans.push_back(matrix[u][col]);
            }
            for (int row = u + 1; row <= d; row++) {
                ans.push_back(matrix[row][r]);
            }
            if (u != d) {
                for (int col = r - 1; col >= l; col--) {
                    ans.push_back(matrix[d][col]);
                }
            }
            if (l != r) {
                for (int row = d - 1; row >= u + 1; row--) {
                    ans.push_back(matrix[row][l]);
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
