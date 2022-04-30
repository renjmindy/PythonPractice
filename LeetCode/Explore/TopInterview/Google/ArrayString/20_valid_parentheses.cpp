class Solution {
public:
    bool isValid(string s) {
      unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
      stack<char> sp;
      for (auto &c : s) {
        if (!mp.count(c)) {
          sp.push(c);
        }
        else {
          if (sp.empty() || mp[c] != sp.top()) {
            return false;
          }
          sp.pop();
        }
      }
      return sp.empty();
    }
};
