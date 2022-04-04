class Solution {
  
private:
  void func(int open, int close, int n, string tmp, vector<string> &ans) {
    if (open == n && close == n) {
      ans.push_back(tmp);
      return;
    }
    if (open < n) {
      func(open + 1, close, n, tmp + '(', ans);
    }
    if (close < n && close < open) {
      func(open, close + 1, n, tmp + ')', ans);
    }
  }
  
public:
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
      func(0, 0, n, "", ans);
      return ans;
    }
};
