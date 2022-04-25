class Solution {
  
private:
  double helper(double x, int n) {
    if (n == 0) {
      return 1;
    }
    if (n & 1) {
      return x * helper(x*x, n/2);
    }
    else {
      return helper(x*x, n/2);
    }
  }
  
public:
    double myPow(double x, int n) {
      double ans = helper(x, n);
      return n > 0 ? ans : 1/ans;
    }
};
