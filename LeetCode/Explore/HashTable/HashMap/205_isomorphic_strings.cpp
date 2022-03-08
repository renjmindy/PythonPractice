class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mps, mpt;
    for (int i = 0; i < s.size(); i++) {
      if (!mps.count(s[i]) && !mpt.count(t[i])) {
        mps[s[i]] = t[i];
        mpt[t[i]] = s[i];
      }
      else {
        if (mps[s[i]] != t[i] && mpt[t[i]] != s[i]) {
          return false;
        }
      }
    }
    return true;
  }
};
