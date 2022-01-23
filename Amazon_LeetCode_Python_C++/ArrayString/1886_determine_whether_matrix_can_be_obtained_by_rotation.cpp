class Solution {

public:
    void tra(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = i; j < mat.size(); j++) {
               swap(mat[i][j], mat[j][i]);
            }
        }
    }
    
public:
    void ref(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
           reverse(mat[i].begin(), mat[i].end());
        }
    }
    
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int c = 3;
        while (mat != target && c > 0) {
            tra(mat);
            ref(mat);
            c--;
        }
        return mat == target;
    }
};
