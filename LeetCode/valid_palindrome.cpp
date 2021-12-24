class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> a, b;
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s.at(i))) {
                a.push_back(tolower(s.at(i)));
            }
        }
        b = a;
        reverse(a.begin(), a.end());
        return a == b;
    }
};
