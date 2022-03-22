// Pop Count

// Complexity Analysis
// Time complexity: O(n \cdot \log n)O(n⋅logn). For each integer xx, in the worst case, we need to perform O(\log n)O(logn) operations, 
// since the number of bits in xx equals to \log x + 1logx+1 and all the bits can be equal to 11. 
// However, on average, each bit will be set n / 2n/2 times, so for each integer xx we will perform \log (x) / 2log(x)/2 operations, 
// therefore, in total, it will cost O(n \cdot \log (n) / 2)O(n⋅log(n)/2) operations.
// Space complexity: O(1)O(1). Since the output array does not count towards the space complexity.

class Solution {

private:
  int popCount(int n) {
    int ans = 0;
    while (n) {
      n &= (n - 1);
      ans++;
    }
    return ans;
  }
  
public:
  vector<int> countBits(int n) {
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
      ans.push_back(popCount(i));
    }
    return ans;
  }
};
