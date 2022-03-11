// Maintain 2 heaps. 1 Min heap and 1 Max Heap. Idea is to maintain the heap in such an order that max heap always contains values less than values in min heap 
// (which can be seen as a sorted array broken into 2 heaps). I will always push the new number into max heap (it can be inserted into min heap as well , then 
// if conditions need to be changed accordingly). Size of heaps should not differ by more than 1. This is done to get the middle elements always available on 
// the top of the heaps and to calculate median in O(1) time.

class MedianFinder {

private:
  priority_queue<int> lo; // max-heap (descending)
  priority_queue<int, vector<int>, greater<int>> hi; // min-heap (ascending)
  
public:
  MedianFinder() {
    
  }
    
  void addNum(int num) {
    lo.push(num);
    hi.push(lo.top());
    lo.pop();
    if (lo.size() < hi.size()) {
      lo.push(hi.top());
      hi.pop();
    }
  }
    
  double findMedian() {
    if (lo.size() > hi.size()) {
      return (double) lo.top();
    }
    else {
      return (double) (lo.top() + hi.top()) * 0.5;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
