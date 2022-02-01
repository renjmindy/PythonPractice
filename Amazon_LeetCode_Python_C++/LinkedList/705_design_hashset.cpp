class MyHashSet {
    vector<bool> vp;
public:
    MyHashSet() {
        vp.resize(2e+6, false);
    }
    
    void add(int key) {
        vp[key] = true;
    }
    
    void remove(int key) {
        vp[key] = false;
    }
    
    bool contains(int key) {
        return vp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
