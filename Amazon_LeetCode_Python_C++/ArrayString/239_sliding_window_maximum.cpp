class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            vector<int> m;
            for (int j = i; j < i + k; j++) {
                m.push_back(nums.at(j));
            }
            ans.push_back(*max_element(m.begin(), m.end()));
            m.clear();
        }
        return ans;
    }
};
