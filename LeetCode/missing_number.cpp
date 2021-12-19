class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums.size();
        for (int i = 0; i < nums.size() + 1; i++) {
            if (i < ans && i != nums.at(i)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        
        n = len(nums)
        
        for i in range(0, n+1, 1):
            if i not in nums:
                return i
