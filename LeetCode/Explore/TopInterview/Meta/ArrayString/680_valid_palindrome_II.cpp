class Solution {
  
private:
  bool isPalindrome(string &s, int low, int high, int check) {
    if (check > 1) {
      return false;
    }
    if (low > high) {
      return true;
    }
    if (s[low] == s[high]) {
      return isPalindrome(s, low + 1, high - 1, check);
    }
    else {
      return isPalindrome(s, low + 1, high, check + 1) || isPalindrome(s, low, high - 1, check + 1);
    }
  }
  
public:
    bool validPalindrome(string s) {
      if (s.size() == 0) {
        return true;
      }
      int l = 0, r = s.size() - 1;
      return isPalindrome(s, l, r, 0);
    }
};
