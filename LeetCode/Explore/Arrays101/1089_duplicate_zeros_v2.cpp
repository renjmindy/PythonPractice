class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == 0 && i + 1 <= arr.size() - 1) {
                int j = arr.size() - 1;
                while (j > i + 1) {
                    arr[j] = arr[j-1];
                    j--;
                }
                arr[i+1] = 0;
                i+=2;
            }
            else {
                i+=1;
            }
        }
    }
};
