class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int countmaxw2[26];
        memset(countmaxw2, 0, sizeof(countmaxw2));
        vector<string> ans;
        for (int i = 0; i < words2.size(); i++) {
            int countw2[26];
            memset(countw2, 0, sizeof(countw2));
            for (int j = 0; j < words2[i].size(); j++) {
                countw2[words2[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                countmaxw2[j] = max(countmaxw2[j], countw2[j]);
            }
        }
        for (int i = 0; i < words1.size(); i++) {
            int countw1[26];
            memset(countw1, 0, sizeof(countw1));
            for (int j = 0; j < words1[i].size(); j++) {
                countw1[words1[i][j] - 'a']++;
            }
            bool found = false;
            for (int j = 0; j < 26; j++) {
                if (countw1[j] < countmaxw2[j]) {
                    found = true;
                }
            }
            if (found) {
                continue;
            }
            else {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};
