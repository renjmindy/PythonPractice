// one pass two pointers

// Complexity Analysis
// Time complexity : O(n)O(n), in length nn of the string. 
// We traverse over each character at-most once, until the two pointers meet in the middle, or when we break and return early.
// Space complexity : O(1)O(1). No extra space required, at all.

class Solution {
public:
  bool isPalindrome(string s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
      while (l < r && !isalnum(s[l])) {
        l++;
      }
      while (l < r && !isalnum(s[r])) {
        r--;
      }
      if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }
    }
    return true;
  }
};
