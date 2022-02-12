class Solution {
  
private:
  string commonPrefix(string s1, string s2) {
    string ans;
    int i = 0, j = 0;
    while (s1[i] == s2[j] && (i < s1.size() && j < s2.size()) ) {
      ans += s1[i];
      i++;
      j++;
    }
    return ans;
  }
  
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) {
      return strs[0];
    }
    string lcp = commonPrefix(strs[0], strs[1]);
    if (lcp.size() == 0) {
      return lcp;
    }
    for (int i = 2; i < strs.size(); i++) {
      lcp = commonPrefix(lcp, strs[i]);
      if (lcp.size() == 0) {
        break;
      }
    }
    return lcp;
  }
};
