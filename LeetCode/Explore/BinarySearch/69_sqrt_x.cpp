class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    long ans;
    int pivot, l = 2, r = x;
    while (l <= r) {
      pivot = l + (r - l) / 2;
      ans = (long)pivot * pivot;
      if (ans > x) {
        r = pivot - 1;
      }
      else if (ans < x) {
        l = pivot + 1;
      }
      else {
        return pivot;
      }
    }
    return r;
  }
};
