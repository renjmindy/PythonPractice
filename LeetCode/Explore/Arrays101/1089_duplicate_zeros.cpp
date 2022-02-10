class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.at(i) == 0) {
                arr.insert(arr.begin() + i + 1, 0);
                arr.erase(arr.begin() + arr.size() - 1);
                i++;
            }
        }
    }
};
