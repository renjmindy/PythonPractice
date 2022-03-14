// one pass array

// Complexity Analysis
// Time complexity : O(n)O(n), in length nn of the string.
// We need to iterate thrice through the string:
// When we filter out non-alphanumeric characters, and convert the remaining characters to lower-case.
// When we reverse the string.
// When we compare the original and the reversed strings.
// Each iteration runs linear in time (since each character operation completes in constant time). Thus, the effective run-time complexity is linear.
// Space complexity : O(n)O(n), in length nn of the string. We need O(n)O(n) additional space to stored the filtered string and the reversed string.

class Solution {
public:
  bool isPalindrome(string s) {
    vector<char> vp, rp;
    for (int i = 0; i < s.size(); i++) {
      if (isalnum(s[i])) {
        vp.push_back(tolower(s[i]));
      }
    }
    rp = vp;
    reverse(rp.begin(), rp.end());
    return vp == rp;
  }
};
