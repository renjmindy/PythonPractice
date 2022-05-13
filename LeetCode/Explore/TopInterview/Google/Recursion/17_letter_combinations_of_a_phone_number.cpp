class Solution {
  
private:
  vector<vector<int> > mapping = {{}, {}, {'a', 'b', 'c'}, 
                                  {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, 
                                  {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, 
                                  {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
  vector<string> ans;
  void helper(int start, int end, string tmp, string digits, vector<string> &ans) {
    // base case
    if (start >= end) {
      ans.push_back(tmp);
      return;
    }
    for (char c : mapping[digits[start] - '0']) {
      helper(start + 1, digits.size(), tmp + c, digits, ans);
    }
  } 
  
public:
    vector<string> letterCombinations(string digits) {
      if (digits.size() == 0) {
        return ans;
      }
      helper(0, digits.size(), "", digits, ans);
      return ans;
    }
};
