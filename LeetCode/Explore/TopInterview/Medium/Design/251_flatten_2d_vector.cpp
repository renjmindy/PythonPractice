class Vector2D {
  
private:
  int x, y;
  vector<vector<int> > ans;
  void update() {
    while (x < ans.size() && y == ans[x].size()) {
      y = 0;
      x++;
    }
  }
  
public:
    Vector2D(vector<vector<int>>& vec) : ans(vec) {
      x = 0, y = 0;
      update();
    }
    
    int next() {
      int val = ans[x][y++];
      update();
      return val;
    }
    
    bool hasNext() {
      return x < ans.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
