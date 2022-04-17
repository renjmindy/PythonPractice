class Solution {
public:
    string addBinary(string a, string b) {
      //vector<int> c(a.size() + b.size(), 0);
      string ans = "";
      /*for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
          c[i + j + 1] = (a[i] - '0' > 0 ? a[i] - '0' : 0) + (b[j] - '0' > 0 ? b[j] - '0' : 0);
          c[i + j] += c[i + j + 1] / 2;
          c[i + j + 1] %= 2;
        }
      }
      int k = 0;
      while (k < c.size() && c[k] == 0) {
        k++;
      }
      while (k < c.size()) {
        ans += to_string(c[k]); 
        k++;
      }
      return ans;*/
      int carry = 0, i = a.size() - 1, j = b.size() - 1;
      while (i >= 0 || j >= 0) {
        int sum = carry + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
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
