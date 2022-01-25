class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums.at(i)) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[target - nums.at(i)]);
            }
            m[nums.at(i)] = i;
        }
        return ans;
    }
};
