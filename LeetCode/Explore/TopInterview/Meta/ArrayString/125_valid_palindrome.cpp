class Solution {
public:
    bool isPalindrome(string s) {
      if (s.size() <= 1) {
        return true;
      }
      string t = "", r = "";
      for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i]) && !isblank(s[i])) {
          t += tolower(s[i]);
        }
      }
      r = t;
      reverse(r.begin(), r.end());
      return r == t;
    }
};
