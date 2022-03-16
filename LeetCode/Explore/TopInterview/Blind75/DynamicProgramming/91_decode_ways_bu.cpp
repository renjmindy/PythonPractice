// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Time Complexity: O(N)O(N), where NN is length of the string. We iterate the length of dp array which is N+1N+1.
// Space Complexity: O(N)O(N). The length of the DP array.

class Solution {
public:
  int numDecodings(string s) {
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1; // base case
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i < s.size() + 1; i++) {
      if (stoi(s.substr(i - 1, 1)) >= 1) {
        dp[i] = dp[i - 1]; 
      }
      if (stoi(s.substr(i - 2, 2)) >= 10 &&
          stoi(s.substr(i - 2, 2)) <= 26) {
        dp[i] += dp[i - 2];
      }
    }
    return dp[s.size()];
  }
};
