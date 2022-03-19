// trie : How to Implement Trie: addWord function
// Complexity Analysis
// Time complexity: \mathcal{O}(M)O(M), where MM is the key length. At each step, we either examine or create a node in the trie. That takes only MM operations.
// Space complexity: \mathcal{O}(M)O(M). In the worst-case newly inserted key doesn't share a prefix with the keys already inserted in the trie. 
// We have to add MM new nodes, which takes \mathcal{O}(M)O(M) space.

// Search in Trie
// Complexity Analysis
// Time complexity: \mathcal{O}(M)O(M) for the "well-defined" words without dots, where MM is the key length, and NN is a number of keys, 
// and \mathcal{O}(N \cdot 26 ^ M)O(N⋅26M) for the "undefined" words. That corresponds to the worst-case situation of searching an undefined 
// word \underbrace{.........}_\text{M times} M times.........​​ which is one character longer than all inserted keys.
// Space complexity: \mathcal{O}(1)O(1) for the search of "well-defined" words without dots, and up to \mathcal{O}(M)O(M) for the "undefined" words, 
// to keep the recursion stack.

class TrieNode{
public:
  bool isEnd;
  TrieNode* child[26];
    
  TrieNode() {
    isEnd = false;
    for (int i = 0; i < 26; i++) {
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
        if (!p->child[c - 'a']) {
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
