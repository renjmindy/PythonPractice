class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int sum = 0, carry = 0, i = digits.size() - 1;
      vector<int> ans;
      digits.at(digits.size() - 1) += 1;
      while (i >= 0) {
        sum = carry + (i >= 0 ? digits[i] : 0);
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
        i--;
      }
      if (carry) {
        ans.push_back(carry);
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
