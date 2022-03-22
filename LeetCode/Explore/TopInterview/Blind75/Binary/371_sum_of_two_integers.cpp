// Bit Manipulation: Easy and Language-Independent

// Complexity Analysis
// Time complexity: \mathcal{O}(1)O(1) because each integer contains 3232 bits.
// Space complexity: \mathcal{O}(1)O(1) because we don't use any additional data structures.

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
