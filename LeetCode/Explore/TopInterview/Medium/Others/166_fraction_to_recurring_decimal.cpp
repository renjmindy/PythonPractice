class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      if (numerator == 0) {
        return "0";
      }
      auto sign = (numerator < 0) ^ (denominator < 0);
      string result = sign ? "-" : "";
      long n = abs(numerator), d = abs(denominator);
      result += to_string(n / d);
      n %= d;
      if (n == 0) {
        return result;
      }
      result += ".";
      unordered_map<long, int> visited;
      while (n) {
        if (!visited.count(n)) {
          visited[n] = result.size();
          n *= 10;
          result += to_string(n / d);
          n %= d;
        }
        else {
          result.insert(visited[n], "(");
          result += ")";
          break;
        }
      }
      return result;
    }
};
