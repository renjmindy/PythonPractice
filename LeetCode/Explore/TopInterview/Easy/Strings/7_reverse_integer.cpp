class Solution {
public:
  int reverse(int x) {
    long long ans = 0;
    while (x) {
      int tmp = ans * 10 + x % 10;
      if (tmp / 10 != ans) {
        return 0;
      }
      ans = tmp;
      x /= 10;
    }
    return ans;
  }
};
