class Solution {
public:
    int numSquares(int n) {
      vector<int> dp(n+1, INT_MAX), vp((int)sqrt(n) + 1);
      dp[0] = 0;
      vp[0] = 0;
      for (int i = 1; i < (int)sqrt(n) + 1; i++) {
        vp[i] = i * i;
      }
      for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < (int)sqrt(n) + 1; j++) {
          if (i < vp[j]) {
            break;
          }
          dp[i] = min(dp[i], dp[i - vp[j]] + 1);
        }
      }
      return dp[n];
    }
};
