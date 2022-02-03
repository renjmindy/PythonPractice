class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int sum = 0, carry = 0, p = num.size() - 1;
        while (p >= 0 || k || carry) {
            if (p >= 0) {
                sum = carry + num[p] + (k % 10);
                carry = sum / 10;
                sum %= 10;
                ans.push_back(sum);
            }
            else {
                sum = carry + k;
                sum %= 10;
                ans.push_back(sum);
                carry += k % 10;
                carry /= 10;
            }
            p--;
            k /= 10;
        }
        if (carry > 0) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
