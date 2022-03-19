// ...

class TrieNode{
public:
  bool isEnd;
  TrieNode* child[26];
    
  TrieNode() {
    isEnd = false;
    for (int i = 0; i < 26; i++){
        child[i] = NULL;
    }
  }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
      TrieNode* p = root;
      for (auto &c : word) {
        if (!p->child[c - 'a']){
          p->child[c - 'a'] = new TrieNode();
        }
        p = p->child[c - 'a'];
      }
      p->isEnd = true;
    }
    
    bool searchTrie(TrieNode* p, string& word, int index) {
      if (!p) {
        return false;
      }
        
      if (index == word.size()) {
        return p->isEnd;
      }
        
      if (word[index] != '.') {
        if (p->child[word[index] - 'a']) {
          return searchTrie(p->child[word[index] - 'a'], word, index + 1);
        }
        else { 
          return false;
        }
      }
      else {
        for(int i = 0; i < 26; i++) {
          if (searchTrie(p->child[i], word, index + 1)) {
            return true;
          }
        }
        return false;
      }
    }
    
    bool search(string word) {
        return searchTrie(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
