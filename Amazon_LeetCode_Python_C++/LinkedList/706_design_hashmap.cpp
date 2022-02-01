class MyHashMap {
    vector<int> vp;
public:
    MyHashMap() {
        vp.resize(2e6, -1);
    }
    
    void put(int key, int value) {
        vp[key] = value;
    }
    
    int get(int key) {
        if (vp[key] == -2) {
            return -1;
        }
        return vp[key];
    }
    
    void remove(int key) {
        vp[key] = -2;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
