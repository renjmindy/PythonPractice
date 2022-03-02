class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    unordered_map<char, int> mps, mpt;
    for (int i = 0; i < s.size(); i++) {
      mps[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++) {
      mpt[t[i]]++;
    }
    if (mps.size() != mpt.size()) {
      return false;
    }
    for (auto &ms : mps) {
      if (ms.second != mpt[ms.first]) {
        return false;
      }
    }
    return true;
  }
};
