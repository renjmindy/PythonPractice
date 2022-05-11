class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int pivot, l = 0, r = arr.size() - 1;
      while (l < r) {
        pivot = l + (r - l) / 2;
        if (arr[pivot] < arr[pivot + 1]) {
          l = pivot + 1;
        }
        else {
          r = pivot;
        }
      }
      return l;
    }
};
