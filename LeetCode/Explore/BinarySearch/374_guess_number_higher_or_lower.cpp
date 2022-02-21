/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      int pivot, l = 1, r = n;
      while (l <= n) {
        pivot = l + (r - l) / 2;
        if (guess(pivot) < 0) {
          r = pivot - 1;
        }
        else if (guess(pivot) > 0) {
          l = pivot + 1;
        }
        else {
          return pivot;
        }
      }
      return -1;
    }
};
