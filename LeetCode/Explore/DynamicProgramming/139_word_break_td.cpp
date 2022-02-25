class Solution {
  
private:
  bool dfs(string &s, set<string> &sp, int n, vector<int> &dp) {
    if (n == s.size()) {
      return true;
    }
    if (dp[n] != -1) {
      return dp[n];
    }
    for (int i = n + 1; i <= s.size(); i++) {
      if (sp.count(s.substr(n, i - n)) && dfs(s, sp, i, dp)) {
        return dp[n] = true;
      }
    }
    return dp[n] = false;
  }
  
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string> sp(wordDict.begin(), wordDict.end());
    vector<int> dp(s.size(), -1);
    return dfs(s, sp, 0, dp);
  }
};
