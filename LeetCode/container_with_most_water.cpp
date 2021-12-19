class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxA = 0;
        while (l < r) {
            maxA = max(maxA, min(height.at(l), height.at(r))*(r - l));
            if (height.at(r) < height.at(l)) {
                r--;
            }
            else {
                l++;
            }
        }
        return maxA;
    }
};
