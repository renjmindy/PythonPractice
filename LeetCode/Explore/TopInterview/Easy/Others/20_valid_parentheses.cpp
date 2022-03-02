class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
    stack<char> sp;
    for (int i = 0; i < s.size(); i++) {
      if (!mp.count(s[i])) {
        sp.push(s[i]);
      } 
      else {
        if (sp.size() == 0 || sp.top() != mp[s[i]]) {
          return false;
        }
        sp.pop();
      }
    }
    return sp.size() == 0;
  }
};
