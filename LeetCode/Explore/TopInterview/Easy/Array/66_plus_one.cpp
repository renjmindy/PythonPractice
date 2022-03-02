class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    int sum = 0, carry = 0, n = digits.size() - 1;
    digits[digits.size() - 1] += 1;
    while (n >= 0) {
      sum = carry + (n >= 0 ? digits[n] : 0);
      carry = sum / 10;
      sum %= 10;
      ans.push_back(sum);
      n--;
    }
    if (carry) {
      ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
