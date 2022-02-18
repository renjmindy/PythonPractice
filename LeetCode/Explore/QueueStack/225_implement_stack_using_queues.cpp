class MyStack {
  
private:
  queue<int> in;
  queue<int> out;
  
public:
  MyStack() {}
    
  void push(int x) {
    while (!in.empty()) {
      out.push(in.front());
      in.pop();
    }
    in.push(x);
    while (!out.empty()) {
      in.push(out.front());
      out.pop();
    }
  }
  
  int pop() {
    int ans = in.front();
    in.pop();
    return ans;
  }
  
  int top() {
    return in.front();
  }
  
  bool empty() {
    return in.empty();
  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
