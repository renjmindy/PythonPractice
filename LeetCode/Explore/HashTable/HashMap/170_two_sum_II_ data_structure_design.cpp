class TwoSum {

private:
  unordered_map<long, int> mp;
  
public:
  TwoSum() {
    
  }
  
  void add(int number) {
    mp[number]++;
  }
  
  bool find(int value) {
    for (auto &m : mp) {
      if (value - m.first != m.first) {
        if (mp.count(value - m.first)) {
          return true;
        }
      }
      else {
        if (m.second > 1) {
          return true;
        }
      }
    }
    return false;
  }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
