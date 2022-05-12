class Solution {
  
private:
  vector<vector<char> > reversiblePairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
  vector<string> generateStroboNumbers(int n, int finalLength) {
    if (n == 0) {
      // 0-digit strobogrammatic number is an empty string.
      return {""};
    }
    if (n == 1) {
      // 1-digit strobogrammatic numbers.
      return {"0", "1", "8"};
    }
    vector<string> prevStroboNums = generateStroboNumbers(n - 2, finalLength);
    vector<string> currStroboNums;
    for (auto &num : prevStroboNums) {
      for (auto &pair : reversiblePairs) {
        // We can only append 0's if it is not first digit.
        if (pair[0] != '0' || n != finalLength) {
          currStroboNums.push_back(pair[0] + num + pair[1]);
        }
      }
    }
    return currStroboNums;
  }
  
public:
    vector<string> findStrobogrammatic(int n) {
      return generateStroboNumbers(n, n);
    }
};
