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
          if (sp.empty() || mp[s[i]] != sp.top()) {
            return false;
          } 
          sp.pop();
        }
      }
      return sp.empty();
    }
};
