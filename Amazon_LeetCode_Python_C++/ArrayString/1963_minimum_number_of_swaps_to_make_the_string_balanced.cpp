class Solution {
public:
    int minSwaps(string s) {
        int swap = 0, balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                balance++;
            }
            else {
                balance--;
            }
            swap = max(swap, balance);
        }
        return swap % 2 == 0 ? swap / 2 : (swap + 1) / 2;
    }
};
