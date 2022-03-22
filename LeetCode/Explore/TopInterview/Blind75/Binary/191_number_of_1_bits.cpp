// Bit Manipulation Trick

// Complexity Analysis
// The run time depends on the number of 11-bits in nn. In the worst case, all bits in nn are 11-bits. In case of a 32-bit integer, the run time is O(1)O(1).
// The space complexity is O(1)O(1), since no additional space is allocated.

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      n &= (n - 1);
      ans++;
    }
    return ans;
  }
};
