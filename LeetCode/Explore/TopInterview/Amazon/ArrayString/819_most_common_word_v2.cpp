class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
      unordered_map<string, int> mp;
      typedef pair<int, string> P;
      priority_queue<P, vector<P>> pq;
      string tmp = "";
      
      for (int i = 0; i < paragraph.size(); i++) {
        if (isalpha(paragraph[i])) {
          tmp += tolower(paragraph[i]);
        }
        else {
          if (tmp.size()) {
            //cout << tmp << " ";
            mp[tmp]++;
            tmp = "";
          }
        }
      }
      
      mp[tmp]++;
      
      for (auto &m : mp) {
        pq.push(make_pair(m.second, m.first));
      }
      
      while (pq.size()) {
        auto x = pq.top();
        pq.pop();
        auto it = find(banned.begin(), banned.end(), x.second);
        if (it == banned.end()) {
          return x.second;
        }
      }
      return "";
    }
};
