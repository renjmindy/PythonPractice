// Insertion of a key to a trie
// Complexity Analysis
// Time complexity : O(m)O(m), where m is the key length.
// In each iteration of the algorithm, we either examine or create a node in the trie till we reach the end of the key. This takes only mm operations.
// Space complexity : O(m)O(m).

// Search for a key in a trie
// Complexity Analysis
// Time complexity : O(m)O(m) In each step of the algorithm we search for the next key character. In the worst case the algorithm performs mm operations.
// Space complexity : O(1)O(1)

// Search for a key prefix in a trie
// Complexity Analysis
// Time complexity : O(m)O(m)
// Space complexity : O(1)O(1)

class Trie {
public:
  bool isEnd; // is there a word ended?
  Trie* child[26]; // child nodes 
  
  Trie() {
    isEnd = false;
    for (int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
  }
  
  void insert(string word) {
    auto p = this;
    for (auto &c : word) {
      if (!p->child[c - 'a']) {
        p->child[c - 'a'] = new Trie();
      }
      p = p->child[c - 'a']; 
    }
    p->isEnd = true;
  }
  
  bool search(string word) {
    auto p = this;
    for (auto &c : word) {
      if (!p->child[c - 'a']) {
        return false;
      }
      p = p->child[c - 'a'];
    }
    return p->isEnd;
  }
  
  bool startsWith(string prefix) {
    auto p = this;
    for (auto &c : prefix) {
      if (!p->child[c - 'a']) {
        return false;
      }
      p = p->child[c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
