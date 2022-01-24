class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        if (s.size() == 0) {
            return true;
        }
        if (s.size() == 1) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '{' || s.at(i) == '[' || s.at(i) == '(') {
                stack.push(s.at(i));
            }
            else {
                if (stack.empty()) {
                    return false;
                }
                if ((s.at(i) == '}' && stack.top() != '{') || 
                    (s.at(i) == ']' && stack.top() != '[') ||
                    (s.at(i) == ')' && stack.top() != '(')) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};
