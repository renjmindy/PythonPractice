class MaxStack {
    vector<int> vp;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        vp.push_back(x);
    }
    
    int pop() {
        if (vp.size() > 0) {
            int tmp = vp.back();
            vp.pop_back();
            return tmp;
        }
        else {
            return -1;
        }
    }
    
    int top() {
        if (vp.size() > 0) {
            return vp.back();
        }
        else {
            return -1;
        }
    }
    
    int peekMax() {
        if (vp.size() > 0) {
            //return *max_element(vp.begin(), vp.end());
            int maxVal = INT_MIN;
            for (int i = vp.size() - 1; i >= 0; i--) {
                maxVal = max(maxVal, vp[i]);
            }
            return maxVal;
        }
        else {
            return -1;
        }
    }
    
    int popMax() {
        if (vp.size() > 0) {
            //int maxVal = *max_element(vp.begin(), vp.end());
            //int maxIdx = max_element(vp.begin(), vp.end()) - vp.begin();
            //vp.erase(vp.begin() + maxIdx);
            //return maxVal;
            int maxIdx = -1, maxVal = INT_MIN;
            for (int i = vp.size() - 1; i >= 0; i--) {
                if (vp[i] > maxVal) {
                    maxVal = vp[i];
                    maxIdx = i;
                }
            }
            if (maxIdx > -1) {
                vp.erase(vp.begin() + maxIdx);
                return maxVal;
            }
            else {
                return -1;
            }
        }
        else {
            return -1;
        }
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
