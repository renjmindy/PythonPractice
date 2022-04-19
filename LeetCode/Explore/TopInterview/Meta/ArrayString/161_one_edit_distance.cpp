class Solution {
public:
    bool isOneEditDistance(string s, string t) {
      int lens = s.size() , lent = t.size();
      if (s == t || abs(lens - lent) > 1) {
        return false;
      } 
      int l = 0, rs = s.size() - 1, rt = t.size() - 1;
      while (l <= rs && l <= rt && s[l] == t[l]) {
        l++;
      }
      while (rs >= 0 && rt >= 0 && s[rs] == t[rt]) {
        rs--;
        rt--;
      }
      return l >= rs && l >= rt;
    }
};
