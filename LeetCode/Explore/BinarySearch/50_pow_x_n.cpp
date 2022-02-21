class Solution {

private:
  double fastPow(double x, long long N) {
    if (N <= 1) {
      return x;
    }
    if (N % 2) {
      return fastPow(x, N/2) * fastPow(x, N/2) * x;
    }
    else {
      return fastPow(x, N/2) * fastPow(x, N/2);
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
