class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> sp;
    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
        int r = sp.top();
        sp.pop();
        int l = sp.top();
        sp.pop();
        if (tokens[i] == "+") {
          sp.push(l + r);
        }
        else if (tokens[i] == "-") {
          sp.push(l - r);
        }
        else if (tokens[i] == "*") {
          sp.push(l * r);
        }
        else {
          sp.push(l / r);
        }
      }
      else {
        sp.push(stoi(tokens[i]));
      }
    }
    return sp.top();
  }
};
