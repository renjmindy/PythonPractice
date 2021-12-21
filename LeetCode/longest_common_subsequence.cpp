class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int col = text2.size() - 1; col >= 0; col--) {
            for (int row = text1.size() - 1; row >= 0; row--) {
                if (text1.at(row) == text2.at(col)) {
                    dp[row][col] = 1 + dp[row+1][col+1];
                }
                else {
                    dp[row][col] = max(dp[row+1][col], dp[row][col+1]);
                }
            }
        }
        return dp[0][0];
    }
};
