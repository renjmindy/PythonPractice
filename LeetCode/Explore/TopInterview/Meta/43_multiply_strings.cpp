class Solution {
public:
    string multiply(string num1, string num2) {
      if (num1.size() == 0 || num2.size() == 0 || num1 == "0" || num2 == "0") {
        return "0";
      }
      string ans = "";
      vector<int> nums(num1.size() + num2.size(), 0);
      for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
          nums[i + j + 1] += ((num1[i] - '0') * (num2[j] - '0'));
          nums[i + j] += nums[i + j + 1] / 10;
          nums[i + j + 1] %= 10;
        }
      }
      int k = 0;
      while (k < nums.size() && nums[k] == 0) {
        k++;
      }
      while (k < nums.size()) {
        ans += to_string(nums[k]);
        k++;
      }
      return ans;
    }
};
