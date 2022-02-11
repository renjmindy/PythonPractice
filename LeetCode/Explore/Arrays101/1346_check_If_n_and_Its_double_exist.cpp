class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int c = count(arr.begin(), arr.end(), 0);
        if (c > 1) {
            return true;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                auto itr1 = find(arr.begin(), arr.end(), (double)arr[i]/2);
                auto itr2 = find(arr.begin(), arr.end(), arr[i]*2);
                if ((itr1 != arr.end()) || (itr2 != arr.end())) {
                    return true;
                }
            }
        }
        return false;
    }
};
