class Solution {
  
public:
    string decodeString(string s) {
      stack<int> countS;
      stack<string> stringS;
      string curS = "";
      int k = 0;
      for (auto &c : s) {
        if (isdigit(c)) {
          k = k * 10 + (c - '0');
        }
        else if (c == '[') {
          countS.push(k);
          stringS.push(curS);
          curS = "";
          k = 0;
        }
        else if (c == ']') {
          string decodeS = stringS.top();
          stringS.pop();
          for (int i = countS.top(); i > 0; i--) {
            decodeS += curS;
          }
          countS.pop();
          curS = decodeS;
        }
        else {
          curS += c;
        }
      }
      return curS;
    }
};
