class Solution {
  
private:
  vector<string> tokenize(string s, string del = " ") {
    vector<string> ans;
    int i = 0, j = s.find(del, i);
    while (j != -1) {
      ans.push_back(s.substr(i, j - i));
      i = j + del.size();
      j = s.find(del, i);
    }
    ans.push_back(s.substr(i, j - i));
    return ans;
  }
  
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
      string clean = "";
      unordered_set<char> sp = {'!', '?', '\'', ';', ',', '.'}; 
      
      for (int i = 0; i < paragraph.size(); i++) {
        if (sp.count(paragraph[i])) {
          clean += "";
        }
        else {
          clean += paragraph[i];
        }
      }
      vector<string> vp = tokenize(clean);
      unordered_map<string, int> mp;
      typedef pair<int, string> P;
      priority_queue<P, vector<P>> pq; // ascending
      
      for (auto &s : vp) {
        string tmp = "";
        bool found = false;
        for (auto &c : s) {
          tmp += tolower(c);
        }
        for (auto &b : banned) {
          if (tmp == b) {
            found = true;
            break;
          }
        }
        if (!found) {
          mp[tmp]++;
        }
      }
      for (auto &m : mp) {
        pq.push(make_pair(m.second, m.first));
      }
      //cout << pq.top().first << " " << pq.top().second << endl;
      return pq.top().second;
    }
};
