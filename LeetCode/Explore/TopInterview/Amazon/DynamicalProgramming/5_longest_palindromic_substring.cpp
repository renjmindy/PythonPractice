class Solution {
public:
    string longestPalindrome(string s) {
      vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
      int idx = -1, maxLen = INT_MIN;
      for (int r = 0; r < s.size(); r++) {
        for (int l = r; l >= 0; l--) {
          if (r == l) {
            dp[l][r] = true;
          }
          else if (r - l == 1) {
            dp[l][r] = (s[l] == s[r]); 
          }
          else {
            dp[l][r] = dp[l + 1][r - 1] && (s[l] == s[r]);
          }
          if (dp[l][r] && r - l + 1 > maxLen) {
            idx = l;
            maxLen = r - l + 1;
          }
        }
      }
      return s.substr(idx, maxLen);
    }
};
