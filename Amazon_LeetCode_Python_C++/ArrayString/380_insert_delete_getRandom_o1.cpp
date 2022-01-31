class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)) {
            return false;
        }
        else {
            m[val] = vals.size();
            vals.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        else {
            int idx = m[val];
            m[vals.back()] = idx;
            m.erase(val);
            swap(vals[idx], vals.back());
            vals.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        int idx = rand() % vals.size(); 
        return vals[idx]; 
    }
    
private: 
    // val -> index in the array 
    unordered_map<int, int> m; 
    vector<int> vals; 
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
