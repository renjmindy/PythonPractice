class Solution {
    
public:
    string delete_invalid_closing(string s, char open_symbol, char close_symbol) {
        int balance = 0;
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == open_symbol) {
                balance++;
            }
            if (s[i] == close_symbol) {
                if (balance > 0) {
                    balance--;
                }
                else {
                    continue;
                }
            }
            t += s[i];
        }
        return t;
    }    
    
public:
    string minRemoveToMakeValid(string s) {
        string t;
        t = delete_invalid_closing(s, '(', ')');
        reverse(t.begin(), t.end());
        t = delete_invalid_closing(t, ')', '(');
        reverse(t.begin(), t.end());
        return t;
        
        /*string first_pass_chars, ans;
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
        return ans;*/
    }
};
