class Solution {

private:
  double powLaw(double x, long long n) {
    if (n == 0) {
      return 1.;
    }
    double half = powLaw(x, n/2);
    if (n % 2 == 0) {
      return pow(half, 2);
    }
    else {
      return pow(half, 2) * x;
    }
  }
  
public:
  double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
      x = 1/x;
      N = -N;
    }
    return powLaw(x, N);
  }
};
