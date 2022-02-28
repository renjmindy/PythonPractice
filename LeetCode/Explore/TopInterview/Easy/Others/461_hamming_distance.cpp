class Solution {
public:
  int hammingDistance(int x, int y) {
    int ans = 0, distance = x ^ y;
    while (distance) {
      ans += (distance & 1);
      distance >>= 1;
    }
    return ans;
  }
};
