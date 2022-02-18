class Solution {
  
private:
  string countString(const string &s, int &idx) {
    string ans;
    while (idx < s.size() && s[idx] != ']') {
      if (!isdigit(s[idx])) {
        ans += s[idx];
        idx++;
      }
      else {
        int k = 0;
        while (idx < s.size() && isdigit(s[idx])) {
          k = k * 10 + (s[idx] - '0');
          idx++;
        }
        // ignore opening bracket '['
        idx++; 
        string dString = countString(s, idx);
        idx++; 
        // ignore closing bracket ']'
        while (k-- > 0) {
          ans += dString;
        }
      }
    }
    return ans;
  }
  
public:
  string decodeString(string s) {
    int idx = 0;
    return countString(s, idx);
  }
};
