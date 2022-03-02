class Solution {
public:
  bool isPalindrome(string s) {
    vector<char> vs, vr;
    for (int i = 0; i < s.size(); i++) {
      if (isalnum(s[i])) {
        vs.push_back(tolower(s[i]));
      }
    }
    vr = vs;
    reverse(vr.begin(), vr.end());
    return vs == vr;
  }
};
