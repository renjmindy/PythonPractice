class MyQueue {
  
private:
  stack<int> in;
  stack<int> out;
  
public:
  MyQueue() {}
    
  void push(int x) {
    while (!in.empty()) {
      out.push(in.top());
      in.pop();
    }
    in.push(x);
    while (!out.empty()) {
      in.push(out.top());
      out.pop();
    }
  }
    
  int pop() {
    int ans = in.top();
    in.pop();
    return ans;
  }
    
  int peek() {
    return in.top();
  }
    
  bool empty() {
    return in.empty();
  }
};
class MyQueue {
  
private:
  stack<int> in;
  stack<int> out;
  
public:
  MyQueue() {}
    
  void push(int x) {
    while (!in.empty()) {
      out.push(in.top());
      in.pop();
    }
    in.push(x);
    while (!out.empty()) {
      in.push(out.top());
      out.pop();
    }
  }
    
  int pop() {
    int ans = in.top();
    in.pop();
    return ans;
  }
    
  int peek() {
    return in.top();
  }
    
  bool empty() {
    return in.empty();
  }
};
