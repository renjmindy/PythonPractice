class Solution {
public:
    string addBinary(string a, string b) {
      string ans;
      int sum = 0, carry = 0, i = a.size() - 1, j = b.size() - 1;
      while (i >= 0 || j >= 0) {
        sum = carry + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
        carry = sum / 2;
        sum %= 2;
        ans += to_string(sum);
        i--;
        j--;
      }
      if (carry) {
        ans += to_string(carry);
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
