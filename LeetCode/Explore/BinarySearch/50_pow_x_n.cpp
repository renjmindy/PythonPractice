class Solution {

private:
  double fastPow(double x, long long N) {
    if (N == 0) {
      return 1;
    }
    else {
      double half = fastPow(x, N/2);
      if (N % 2) {
        return half * half * x;
      }
      else {
        return half * half;
      }
    }
  }
  
public:
  double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
      x = 1/x;
      N = -N;
    }
    return fastPow(x, N);
  }
};
