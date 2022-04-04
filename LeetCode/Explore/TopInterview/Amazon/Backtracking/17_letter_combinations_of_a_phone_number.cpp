class Solution {
  
private:
  void func(int idx, string &seq, vector<string> &ans, string &digits, vector<string> &mp) {
    if (idx == digits.size()) {
      ans.push_back(seq);
      return;
    }
    int curr_digit = digits[idx] - '0';
    string available_letters = mp[curr_digit];
    for (int i = 0; i < available_letters.size(); i++) {
      seq.push_back(available_letters[i]);
      func(idx + 1, seq, ans, digits, mp);
      seq.pop_back();
    }
  }
  
public:
    vector<string> letterCombinations(string digits) {
      if (digits.size() == 0) {
        return {};
      }
      vector<string> m(10, "");
      m[2] = "abc";
      m[3] = "def";
      m[4] = "ghi";
      m[5] = "jkl";
      m[6] = "mno";
      m[7] = "pqrs";
      m[8] = "tuv";
      m[9] = "wxyz";
      
      vector<string> ans;
      string seq = "";
      func(0, seq, ans, digits, m);
      return ans;
    }
};
