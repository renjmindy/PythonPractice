class Solution {
  
public:
  int numDecodings(string s) {
    if (s[0] == '0') {
      return 0;
    }
    int one = 1;
    int two = 1;
    
    for (int i = 1; i < s.size(); i++) {
      int ans = 0;
      if (s[i] != '0') {
        ans = one;
      }
      if (stoi(s.substr(i - 1, 2)) >= 10 && stoi(s.substr(i - 1, 2)) <= 26) {
        ans += two;
      }
      two = one;
      one = ans;
    }
    return one;
  }
};
