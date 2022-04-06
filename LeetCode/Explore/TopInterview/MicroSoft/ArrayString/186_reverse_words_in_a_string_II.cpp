class Solution {
public:
    void reverseWords(vector<char>& s) {
      reverse(s.begin(), s.end());
      int l = 0, r = 0;
      while (l < s.size()) {
        while (r < s.size() && !isblank(s[r])) {
          r++;
        }  
        if (l < r) {
          reverse(s.begin() + l, s.begin() + r);
        }
        r++;
        l = r;
      }
    }
};
