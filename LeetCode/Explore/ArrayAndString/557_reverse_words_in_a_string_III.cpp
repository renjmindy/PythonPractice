class Solution {
public:
    string reverseWords(string s) {
      int r = 0, l = 0;
      string ans;
      while (l < s.size()) {
        while (r < s.size() && !isblank(s[r])) {
          r++;
        }
        if (r > l) {
          reverse(s.begin() + l, s.begin() + r);
          for (int i = l; i < r; i++) {
            ans += s[i];
          }
          ans += ' ';
        }
        r++; 
        l = r;
      }
      ans.erase(remove(ans.end() - 1, ans.end(), ' '), ans.end());
      return ans;
    }
};
