class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int pivot, l = 0, r = letters.size() - 1;
    if (letters[r] <= target) {
      return letters[0];
    }
    while (l < r) {
      pivot = l + (r - l) / 2;
      if (letters[pivot] <= target) {
        l = pivot + 1;
      }
      else {
        r = pivot;
      }
    }
    return letters[r];
  }
};
