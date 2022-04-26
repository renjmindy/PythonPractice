class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int> nums;
      digits[digits.size() - 1] += 1;
      int sum = 0, carry = 0, n = digits.size() - 1;
      while (n >= 0) {
        sum = carry + digits[n];
        carry = sum / 10;
        sum %= 10;
        nums.push_back(sum);
        n--;
      }
      if (carry) {
        nums.push_back(carry);
      }
      reverse(nums.begin(), nums.end());
      return nums;
    }
};
