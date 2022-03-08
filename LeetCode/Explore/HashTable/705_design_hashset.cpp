class MyHashSet {
  
private:
  vector<bool> vp;
  
public:
  MyHashSet() {
    vp.resize(1e+7, false); // assign enough space
  }
  
  void add(int key) {
    vp[key] = true;
  }
  
  void remove(int key) {
    vp[key] = false;
  }
  
  bool contains(int key) {
    if (vp[key]) {
      return true;
    }
    else {
      return false;
    }
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
