class Solution {
  
private:
  int toNext(int n) {
    int sum = 0;
    while (n > 0) {
      int d = n % 10;
      n /= 10;
      sum += d * d;
    }
    return sum;
  }
  
public:
  bool isHappy(int n) {
    set<int> sp;
    while (n != 1 && !sp.count(n)) {
      sp.insert(n);
      n = toNext(n);
    }
    return n == 1;
  }
};
