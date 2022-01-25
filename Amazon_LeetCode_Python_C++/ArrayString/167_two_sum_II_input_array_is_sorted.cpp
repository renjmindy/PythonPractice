class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < numbers.size(); i++) {
            if (mp.find(target - numbers[i]) != mp.end()) {
                ans.push_back(mp[target-numbers[i]]);
                ans.push_back(i + 1);
            }
            mp[numbers[i]] = i + 1;
        }
        return ans;
    }
};
