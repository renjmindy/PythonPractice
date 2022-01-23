class Solution {
public:
    string removeVowels(string s) {
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) != 'a' && tolower(s[i]) != 'e' && tolower(s[i]) != 'i' &&
                tolower(s[i]) != 'o' && tolower(s[i]) != 'u') {
                t += s[i];
            }
        }
        return t;
    }
};
