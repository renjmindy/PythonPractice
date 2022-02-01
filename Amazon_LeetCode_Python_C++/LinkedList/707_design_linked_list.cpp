class MyLinkedList {
    vector<int> vp;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (index < 0 || index >= vp.size()) {
            return -1;
        }
        else {
            return vp[index];
        }
    }
    
    void addAtHead(int val) {
        vp.insert(vp.begin(), val);
    }
    
    void addAtTail(int val) {
        vp.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > vp.size()) return;
        if (index == vp.size()) {
            vp.push_back(val);
            return;
        }
        vp.insert(vp.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= vp.size()) return;
        vp.erase(vp.begin() + index);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
