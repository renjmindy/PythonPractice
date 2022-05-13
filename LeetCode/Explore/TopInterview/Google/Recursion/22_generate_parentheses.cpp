class Solution {
  
private:
  vector<string> ans;
  void helper(int start, int end, int idx, string tmp, vector<string> &ans) {
    // base case
    if (start == idx && end == idx) {
      ans.push_back(tmp);
      return;
    }
    if (start < idx) {
      helper(start + 1, end, idx, tmp + '(', ans);
    }
    if (end < idx && end < start) {
      helper(start, end + 1, idx, tmp + ')', ans);
    }
  }
  
public:
    vector<string> generateParenthesis(int n) {
      helper(0, 0, n, "", ans);
      return ans;
    }
};
