// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      int pivot, l = 1, r = n;
      while (l <= r) {
        pivot = l + (r - l) / 2;
        if (!isBadVersion(pivot)) {
          l = pivot + 1;
        }
        else {
          r = pivot - 1;
        }
      }
      return l;
    }
};
