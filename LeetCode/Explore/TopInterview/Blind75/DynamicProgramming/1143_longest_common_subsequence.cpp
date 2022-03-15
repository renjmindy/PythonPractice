// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Time complexity : O(M \cdot N)O(M⋅N).
// We're solving M \cdot NM⋅N subproblems. Solving each subproblem is an O(1)O(1) operation.
// Space complexity : O(M \cdot N)O(M⋅N).
// We'e allocating a 2D array of size M \cdot NM⋅N to save the answers to subproblems.

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i < text1.size() + 1; i++) {
      for (int j = 1; j < text2.size() + 1; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[text1.size()][text2.size()];
  }
};
