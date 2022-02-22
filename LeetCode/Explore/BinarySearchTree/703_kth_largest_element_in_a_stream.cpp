class KthLargest {
  
private:
  int kth;
  priority_queue<int, vector<int>, greater<int> > minHeap;
  
public:
  KthLargest(int k, vector<int>& nums) {
    kth = k;
    for (auto &num : nums) {
      add(num);
    }
  }
  
  int add(int val) {
    minHeap.push(val);
    if (minHeap.size() > kth) {
      minHeap.pop();
    }
    return minHeap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
