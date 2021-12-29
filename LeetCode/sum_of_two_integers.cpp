class Solution {
public:
    int getSum(int a, int b) {
        long mask = 0xFFFFFFFF;
        while (b != 0) {
            int ans = (a ^ b) & mask;
            int car = ((a & b) & mask) << 1;
            a = ans;
            b = car;
        }
        return a < INT_MAX ? a : ~(a ^ mask);
    }
};
