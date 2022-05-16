class Solution {
public:
    string longestPalindrome(string s) {
      int idx = -1, maxLen = 0;
      vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false)); 
      for (int col = 0; col < s.size(); col++) {
        for (int row = col; row >= 0; row--) {
          if (col == row) {
            dp[row][col] = true;
          }
          else if (col - row == 1) {
            dp[row][col] = (s[col] == s[row]);
          } 
          else {
            dp[row][col] = (dp[row + 1][col - 1]) && (s[col] == s[row]);
          }
          if (dp[row][col] && col - row + 1 > maxLen) {
            idx = row;
            maxLen = max(maxLen, col - row + 1);
          }
        }
      }
      return s.substr(idx, maxLen);
    }
};
