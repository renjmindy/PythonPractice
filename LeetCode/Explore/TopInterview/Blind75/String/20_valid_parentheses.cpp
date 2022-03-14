// one pass stack

// Complexity analysis
// Time complexity : O(n)O(n) because we simply traverse the given string one character at a time and push and pop operations on a stack take O(1)O(1) time.
// Space complexity : O(n)O(n) as we push all opening brackets onto the stack and in the worst case, we will end up pushing all the brackets onto the stack. e.g. ((((((((((.

class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
    stack<char> sp;
    for (int i = 0; i < s.size(); i++) {
      if (!mp.count(s[i])) { // store open brackets in stack
        sp.push(s[i]);
      }
      else {
        if (sp.empty() || sp.top() != mp[s[i]]) {
          return false;
        }
        sp.pop();
      }
    }
    return sp.empty();
  }
};
