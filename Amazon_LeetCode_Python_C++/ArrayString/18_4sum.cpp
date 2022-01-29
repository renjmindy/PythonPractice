class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int> &nums, int target, int i, int k) {
        vector<vector<int> > res;
        if (i == nums.size()) {
            return res;
        }
        int avg = target / k;
        if  (nums[i] > avg || avg > nums.back()) {
            return res;
        }
        if (k == 2) {
            return twoSum(nums, target, i);
        }
        for (int j = i; j < nums.size(); j++) {
            if (j == i || nums[j - 1] != nums[j]) {
                for (vector<int> &subset : kSum(nums, target - nums[j], j + 1, k - 1)) {
                    res.push_back({nums[j]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
        return res;
    }
    
    vector<vector<int> > twoSum(vector<int> &nums, int target, int i) {
        vector<vector<int> > res;
        int lo = i, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target || (lo > i && nums[lo] == nums[lo - 1])) {
                lo++;
            }
            else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
                hi--;
            }
            else {
                res.push_back({nums[lo], nums[hi]});
                lo++;
                hi--;
            }
        }
        return res;
    }
};
