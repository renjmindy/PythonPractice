class RandomizedSet {

private:
  unordered_map<int, int> mp;
  vector<int> vp;
  
public:
  RandomizedSet() {
    
  }
  
  bool insert(int val) {
    if (!mp.count(val)) {
      mp[val] = vp.size();
      vp.push_back(val);
      return true;
    }
    else {
      return false;
    }
  }
  
  bool remove(int val) {
    if (mp.count(val)) {
      mp[vp.back()] = mp[val];
      swap(vp[mp[val]], vp.back());
      mp.erase(val);
      vp.pop_back();
      return true;
    }
    else {
      return false;
    }
  }
  
  int getRandom() {
    return vp[rand() % vp.size()]; 
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
