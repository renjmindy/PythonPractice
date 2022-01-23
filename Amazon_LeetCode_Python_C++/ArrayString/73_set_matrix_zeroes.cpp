class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> r, c;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    if (!r.count(i)) {
                        r.insert(i);
                    }
                    if (!c.count(j)) {
                        c.insert(j);
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (r.count(i) || c.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
