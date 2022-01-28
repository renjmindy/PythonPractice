class Solution {
public:
    vector<int> partitionLabels(string s) {
        int idx[26], pivot = 0, max_idx = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            idx[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size(); i++) {
            max_idx = max(max_idx, idx[s[i] - 'a']);
            //cout << i << " " << max_idx << endl;
            if (i == max_idx) {
                ans.push_back(i - pivot + 1);
                pivot = i + 1;
            }
        }
        return ans;
    }
};
