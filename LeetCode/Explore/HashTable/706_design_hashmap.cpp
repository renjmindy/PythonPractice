class MyHashMap {

private:
  vector<int> vp;

public:
  MyHashMap() {
    vp.resize(1e+7, -1);
  }
  
  void put(int key, int value) {
    vp[key] = value;
  }
  
  int get(int key) {
    return vp[key];
  }
  
  void remove(int key) {
    vp[key] = -1;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
