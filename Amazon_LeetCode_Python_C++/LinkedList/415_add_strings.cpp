class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int sum = 0, carry = 0, p1 = num1.size() - 1, p2 = num2.size() - 1;
        while (p1 >= 0 || p2 >= 0) {
            sum = carry + (p1 >= 0 ? num1[p1] - '0' : 0) + (p2 >= 0 ? num2[p2] - '0' : 0);
            carry = sum / 10;
            sum %= 10;
            ans += to_string(sum);
            p1--;
            p2--;
        }
        
        if (carry > 0) {
            ans+= to_string(carry);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

        
