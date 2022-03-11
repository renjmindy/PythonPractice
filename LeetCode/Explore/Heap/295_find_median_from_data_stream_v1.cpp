class MedianFinder {
  
private:
  vector<int> store;
  
public:
  MedianFinder() {
    
  }
  
  void addNum(int num) {
    store.push_back(num);
  }
  
  double findMedian() {
    sort(store.begin(), store.end());
    return store.size() & 1 ? (double)store[store.size() / 2] : ((double) store[store.size() / 2 - 1] + store[store.size() / 2]) / 2;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
