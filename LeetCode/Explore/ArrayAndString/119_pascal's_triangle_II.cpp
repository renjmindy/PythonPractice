class Solution {
public:
    vector<int> getRow(int rowIndex) {
      int numRows = rowIndex + 1;
      vector<vector<int> > ans;
      for (int i = 0; i < numRows; i++) {
        vector<int> vp(i + 1, 0);
        vp[0] = 1;
        vp[i] = 1;
        for (int j = 1; j < i; j++) {
          vp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(vp);
      }
      return ans[rowIndex];
    }
};
