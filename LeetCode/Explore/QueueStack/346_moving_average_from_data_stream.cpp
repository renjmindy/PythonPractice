class MovingAverage {
  
private:
  int n;
  double sum;
  queue<int> qp;
  
public:
    MovingAverage(int size) {
      n = size;
    }
    
    double next(int val) {
      if (qp.size() >= n) {
        sum -= qp.front();
        qp.pop();
      }
      sum += val;
      qp.push(val);
      return sum / qp.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
