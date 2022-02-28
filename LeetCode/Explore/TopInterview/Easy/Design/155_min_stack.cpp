class MinStack {
  
private:
  vector<int> vp;
  
public:
  MinStack() {}
  
  void push(int val) {
    vp.push_back(val);
  }
  
  void pop() {
    vp.pop_back();
  }
  
  int top() {
    return vp.back();
  }
  
  int getMin() {
    return *min_element(vp.begin(), vp.end());
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
