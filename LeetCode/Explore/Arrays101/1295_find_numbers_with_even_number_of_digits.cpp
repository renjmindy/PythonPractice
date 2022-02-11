class Solution {
    
private:
    int getDigits(int num) {
        int count = 0;
        while (num / 10 >= 1) {
            num /= 10;
            count++;
        }
        return count + 1;
    }
    
public:
    int findNumbers(vector<int>& nums) {
        int countNums = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!(getDigits(nums[i]) % 2)) {
                countNums++;
            }
        }
        return countNums;
    }
};
