class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int max1 = rob_simple(nums, 0, nums.size() - 2);
        int max2 = rob_simple(nums, 1, nums.size() - 1);
        
        return max(max1, max2);
    }
    
public:
    int rob_simple(vector<int>& n, int s, int e) {
        int l = 0, r = 0;
        for (int i = s; i <= e; i++) {
            int tmp = r;
            r = max(r, l + n.at(i));
            l = tmp;
        }
        return r;
    }
};
