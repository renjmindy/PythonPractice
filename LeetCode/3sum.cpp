class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i && nums.at(i) == nums.at(i-1)) continue;
            int a = nums.at(i);
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if ((a + nums.at(l) + nums.at(r)) < 0) {
                    l++;
                    if (nums.at(l) == nums.at(l-1)) continue;
                }
                else if ((a + nums.at(l) + nums.at(r)) > 0) {
                    r--;
                    if (nums.at(r) == nums.at(r+1)) continue;
                }
                else {
                    if ((l > (i+1)) && nums.at(l) == nums.at(l-1)) {
                        l++;
                        continue;
                    }
                    if ((r < (nums.size() - 1)) && nums.at(r) == nums.at(r+1)) {
                        r--;
                        continue;
                    }
                    ans.push_back({a, nums.at(l), nums.at(r)});
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};
