// dynamical programming: bottom-up tabulation

// Complexity Analysis
// nn is the length of the input string.
// Time complexity : O(n^3)O(n3). There are two nested loops, and substring computation at each iteration. 
// Overall that results in O(n^3)O(n3) time complexity.
// Space complexity : O(n)O(n). Length of pp array is n+1n+1.

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string> sp(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && sp.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};
