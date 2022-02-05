class TwoSum {
    
private:
    int num_sorted;
    vector<int> vp;
    void sorted_num() {
        if (num_sorted == vp.size()) {
            return;
        }
        sort(vp.begin() + num_sorted, vp.end());
        inplace_merge(vp.begin(), vp.begin() + num_sorted, vp.end());
        num_sorted = vp.size();
    }
    
public:
    TwoSum(): num_sorted(0), vp() {}
    
    void add(int number) {
        vp.push_back(number);
    }
    
    bool find(int value) {
        sorted_num();
        auto l = 0, r = (int)vp.size() - 1;
        while (l < r) {
            auto sum = 0LL + vp[l] + vp[r];
            if (sum < value) {
                l++;
            }
            else if (sum > value) {
                r--;
            }
            else {
                return true;
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
