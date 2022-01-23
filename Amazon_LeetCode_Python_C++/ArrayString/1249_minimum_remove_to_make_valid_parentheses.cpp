class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string first_pass_chars, ans;
        int balance = 0, open_seen = 0, open_to_keep = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                balance++;
                open_seen++;
            }
            if (s[i] == ')') {
                if (balance > 0) {
                    balance--;
                }
                else {
                    continue;
                }
            }
            first_pass_chars += s[i];
        }
        //cout << s << "   " << first_pass_chars << endl;
        open_to_keep = open_seen - balance;
        for (int i = 0; i < first_pass_chars.size(); i++) {
            if (first_pass_chars[i] == '(') {
                open_to_keep--;
                if (open_to_keep < 0) {
                    continue;
                }
            }
            ans += first_pass_chars[i];
        }
        return ans;
    }
};
