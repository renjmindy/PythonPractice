class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int sum = 0, carry = 0, p = digits.size() - 1;
        while (p >= 0) {
            sum = carry + (p >= 0 ? digits[p] : 0);
            carry = sum / 10;
            sum %= 10;
            ans.push_back(sum);
            p--;
        }
        if (carry) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        ans.back() += 1;
        if (ans.back() / 10 >= 1) {
            carry = ans.back() / 10;
            p = ans.size() - 1;
            ans.back() -= 1;
            while (p >= 0 && carry >= 1) {
                sum = carry + (p >= 0 ? ans[p] : 0);
                carry = sum / 10;
                sum %= 10;
                ans[p] = sum;
                p--;
            }
            if (carry) {
                ans.insert(ans.begin(), carry);
            }
        }
        return ans;
    }
};
