class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      set<string> sp(wordDict.begin(), wordDict.end());
      vector<bool> dp(s.size() + 1, false);
      dp[0] = true;
      for (int i = 1; i < s.size() + 1; i++) {
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
