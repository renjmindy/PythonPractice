// one pass two pointers sliding window dynamical programming

// Complexity Analysis
// Time complexity : O(n^2)O(n2). This gives us a runtime complexity of O(n^2)O(n2).
// Space complexity : O(n^2)O(n2). It uses O(n^2)O(n2) space to store the table.

class Solution {
public:
  string longestPalindrome(string s) {
    int iniCha = -1, maxLen = INT_MIN;
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
    for (int r = 0; r < s.size(); r++) {
      for (int l = r; l >= 0; l--) {
        if (l == r) { // base case 1
          dp[l][r] = true;
        }
        else if (r - l == 1) { // base case 2
          dp[l][r] = (s[l] == s[r]);
        }
        else {
          dp[l][r] = (dp[l + 1][r - 1] && s[l] == s[r]);
        }
        if (dp[l][r] && r - l + 1 > maxLen) {
          maxLen = r - l + 1;
          iniCha = l;
        }
      }
    }
    return s.substr(iniCha, maxLen);
  }
};
