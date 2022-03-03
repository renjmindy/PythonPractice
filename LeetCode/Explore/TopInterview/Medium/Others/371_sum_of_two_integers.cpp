class Solution {
public:
  int getSum(int a, int b) {
    long long mask = 0xffffffff;
    while (b) {
      int ans = (a ^ b) & mask;
      int carry = ((a & b) & mask) << 1;
      a = ans;
      b = carry;
    }
    return a < INT_MAX ? a : ~(a ^ mask);
  }
};
