// Bit by Bit

// Complexity
// Time Complexity: \mathcal{O}(1)O(1). Though we have a loop in the algorithm, the number of iteration is fixed regardless the input, 
// since the integer is of fixed-size (32-bits) in our problem.
// Space Complexity: \mathcal{O}(1)O(1), since the consumption of memory is constant regardless the input.

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0, pow = 31;
    while (n) {
      ans += (n & 1) << pow;
      n >>= 1;
      pow--;
    }
    return ans;
  }
};
