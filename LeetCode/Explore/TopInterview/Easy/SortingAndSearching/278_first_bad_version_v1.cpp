// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int v = 1;
    while (v <= n) {
      if (isBadVersion(v)) {
        break;
      }
      v++;
    }
    return v;
  }
};
