class Trie {
public:
    Trie *ch[26];
    bool is_end;
    Trie() {
        for(int i = 0; i < 26; i++) ch[i] = nullptr;
        is_end = false;
    }
    
    void insert(string word) {
        Trie * tmp = this;
        for(char c : word) {
            if(tmp->ch[c-'a'] == nullptr) {
                tmp->ch[c-'a'] = new Trie();
            }
            tmp = tmp->ch[c-'a'];
        }
        tmp->is_end = true;
    }
    
    bool search(string word) {
        Trie * tmp = this;
        for(char c : word) {
            if(tmp->ch[c-'a'] == nullptr) {
                return false;
            }
            tmp = tmp->ch[c-'a'];
        }
        return tmp->is_end;
    }
    
    bool startsWith(string prefix) {
        Trie * tmp = this;
        for(char c : prefix) {
            if(tmp->ch[c-'a'] == nullptr) {
                return false;
            }
            tmp = tmp->ch[c-'a'];
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
