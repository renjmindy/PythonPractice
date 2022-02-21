class Solution {
public:
  bool isPerfectSquare(int num) {
    long long pivot, l = 1, r = num;
    while (l <= r) {
      pivot = l + (r - l) / 2;
      if ((long long)pivot * pivot == num) {
        return true;
      }
      else if ((long long)pivot * pivot > num) {
        r = pivot - 1;
      }
      else {
        l = pivot + 1;
      }
    }
    return false;
  }
};
