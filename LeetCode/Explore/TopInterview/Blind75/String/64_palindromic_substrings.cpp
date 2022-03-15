// dynamical programming

// Complexity Analysis
// Time Complexity: O(N^2)O(N2) for input string of length NN. The number of dynamic programming states that need to calculated is the same as the number of substrings 
// i.e. {N \choose 2} = N(N-1)/2(2N​)=N(N−1)/2. Each state can be calculated in constant time using a previously calculated state. 
// Thus overall time take in the order of O(N^2)O(N2).
// Space Complexity: O(N^2)O(N2) for an input string of length NN. We need to allocate extra space to hold all N \choose 2(2N​) dynamic programming states.

class Solution {
public:
  int countSubstrings(string s) {
    if (s.size() == 0) {
      return 0;
    }
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
    int ans = 0;
    
    // base case: single letter substrings
    for (int i = 0; i < s.size(); i++, ans++) {
      dp[i][i] = true;
    }
    
    // base case: double letter substrings
    for (int i = 0; i < s.size() - 1; i++) {
      dp[i][i + 1] = (s[i] == s[i + 1]);
      ans += dp[i][i + 1];
    }
    
    // all other cases: substrings of length equal to or greater than 3
    for (int i = 2; i < s.size(); i++) {
      for (int j = 0, k = i + j; k < s.size(); j++, k++) {
        dp[j][k] = (dp[j + 1][k - 1] && s[j] == s[k]);
        ans += dp[j][k];
      }
    }
    return ans;
  }
};
