class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1) {
      return x;
    }
    // binary search
    long ans;
    int pivot, l = 2, r = x;
    while (l <= r) { // non-index
      pivot = l + (r - l) / 2;
      ans = (long)pow(pivot, 2);
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
