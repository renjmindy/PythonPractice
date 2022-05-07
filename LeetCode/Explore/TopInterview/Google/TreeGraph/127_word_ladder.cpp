class Solution {
public:
  
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
    
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
      return 0;
    }
        
    int ans = 0;
    set<string> visit;
    queue<string> q;
        
    for(auto &word: wordList) {
      visit.insert(word);
    }
        
    q.push(beginWord);
        
    while(!q.empty()) {
      int n = q.size();
      ans++;
      
      while(n) {
        string top = q.front();
        q.pop();
        
        for(int i = 0; i < top.size(); i++) {
          string tmp = top;
          
          for(char c = 'a'; c <= 'z'; c++) {
            tmp[i] = c;
            
            if(tmp == endWord) {
              ans++;
              return ans;
            }
            if(tmp == top) {
              continue;
            }
            if(visit.count(tmp)) {
              q.push(tmp);
              visit.erase(tmp);
            }
          }
        }
        n--;
      }
    }
    return 0;
  } 
};

