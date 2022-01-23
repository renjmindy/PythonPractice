class Solution {
public:
    string reverseVowels(string s) {
        vector<int> c;
        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || 
                tolower(s[i]) == 'o' || tolower(s[i]) == 'u') {
                c.push_back(i);
            }
        }
        int l = 0, r = c.size() - 1;
        while (l < r) {
            swap(s[c[l]], s[c[r]]);
            l++;
            r--;
        }
        return s;
    }
};
