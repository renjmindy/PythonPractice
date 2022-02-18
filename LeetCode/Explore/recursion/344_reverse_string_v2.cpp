class Solution {
  
private:
  void recursion(vector<char> &s, int l, int r) {
    if (l >= r) {
      return;
    }
    else {
      swap (s[l], s[r]);
      l++;
      r--;
      recursion(s, l, r);
    }
  }
  
public:
    void reverseString(vector<char>& s) {
      //reverse(s.begin(), s.end());
      /*int l = 0, r = s.size() - 1;
      while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
      }*/
      recursion(s, 0, s.size() - 1);
    }
};
