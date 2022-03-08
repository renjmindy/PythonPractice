class Solution {
  
private:
  int getNext(int n) {
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      sum += pow(digit, 2);
      n /= 10;
    }
    return sum;
  }
  
public:
  bool isHappy(int n) {
    unordered_set<int> digits;
    while (n != 1) {
      n = getNext(n);
      if (!digits.count(n)) {
        digits.insert(n);
      }
      else {
        return false;
      }
    }
    return true;
  }
};
