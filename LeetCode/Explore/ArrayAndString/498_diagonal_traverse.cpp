class Solution {
  
private:
  void traverseDiagonal(vector<vector<int>>&mat, vector <int> &ans, int l, int r, bool shouldReverse) {
    int p = mat.size(), q = mat[0].size();
    vector<int> tmp;

    while(l < p and r >= 0) {
      tmp.push_back(mat[l][r]);
      l++;
      r--;
    }

    if(shouldReverse) {
      reverse(tmp.begin(), tmp.end());
    }

    for(auto &i : tmp) {
      ans.push_back(i);
    }
  }
  
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector <int> ans;
        
    int p = mat.size(), q = mat[0].size();
    bool shouldReverse = true;
      
    for(int j = 0; j < q; j++) {
      // Diagonal start point = (0, j)	
      traverseDiagonal(mat, ans, 0, j, shouldReverse);
      shouldReverse = !shouldReverse;
    }

    for(int i = 1; i < p; i++) {
      // Diagonal start point = (i, q - 1)	
      traverseDiagonal(mat, ans, i, q - 1, shouldReverse);
      shouldReverse = !shouldReverse;
    }
    return ans;
  }
};
