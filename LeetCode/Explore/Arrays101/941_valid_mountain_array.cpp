class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0;
        for (int r = 0; r < arr.size() - 1; r++) {
            if (arr[r+1] > arr[r]) {
                l++;
            }
        }
        if (l == 0 || l == arr.size() - 1) {
            return false;
        }
        while ((l < arr.size() - 1) && arr[l] > arr[l+1]) {
            l++;
        }
        return l == arr.size() - 1;
    }
};
