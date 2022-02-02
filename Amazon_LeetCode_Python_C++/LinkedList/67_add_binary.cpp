class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int sum = 0, carry = 0, p1 = a.size() - 1, p2 = b.size() - 1;
        while (p1 >= 0 || p2 >= 0) {
            sum = carry + (p1 >= 0 ? a[p1] - '0' : 0) + (p2 >= 0 ? b[p2] - '0' : 0);
            carry = sum / 2;
            sum %= 2;
            ans += to_string(sum);
            p1--;
            p2--;
        }
        if (carry > 0) {
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
