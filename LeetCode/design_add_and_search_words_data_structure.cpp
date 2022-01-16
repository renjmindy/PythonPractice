class TrieNode{
public:
    bool is_end;
    TrieNode* ch[26];
    
    TrieNode() : is_end(false) {
        for(int i = 0; i < 26; i++){
            ch[i] = NULL;
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
        int i, j;
        TrieNode* cur = root;
        for(i = 0; i < word.length(); i++){
            j = word[i] - 'a';
            if(cur->ch[j] == NULL){
                cur->ch[j] = new TrieNode();
            }
            cur = cur->ch[j];
        }
        cur->is_end = true;
    }
    
    bool searchTrie(TrieNode* cur, string& word, int index){
        if(cur == NULL){
            return false;
        }
        
        if(index == word.length()){
            return cur->is_end;
        }
        
        if(word[index] != '.'){
            int childIndex = word[index] - 'a';
            if(cur->ch[childIndex] != NULL){
                return searchTrie(cur->ch[childIndex], word, index + 1);
            }
            else{
                return false;
            }
        }
        else{
            for(int i = 0; i < 26; i++){
                if(searchTrie(cur->ch[i], word, index + 1)){
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
