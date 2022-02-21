/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
  int search(const ArrayReader& reader, int target) {
    int pivot, l = 0, r = pow(10, 4);
    while (l <= r) {
      pivot = l + (r - l) / 2;
      if (reader.get(pivot) == INT_MAX) {
        r = pivot - 1;
      }
      else if (reader.get(pivot) > target) {
        r = pivot - 1;
      }
      else if (reader.get(pivot) < target) {
        l = pivot + 1;
      }
      else {
        return pivot;
      }
    }
    return -1;
  }
};
