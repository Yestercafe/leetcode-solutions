class StackOfPlates {
    int cap;
    vector<vector<int>> s;
public:
    StackOfPlates(int cap): cap{cap} {

    }
    
    void push(int val) {
        if (cap == 0) return;
        if (s.empty() || s.back().size() == cap) {
            s.push_back({});
        }
        s.back().push_back(val);
    }
    
    int pop() {
        if (s.empty()) {
            return -1;
        }
        int ret = s.back().back();
        s.back().pop_back();
        if (s.back().empty()) s.pop_back();
        return ret;
    }
    
    int popAt(int index) {
        if (s.size() <= index) {
            return -1;
        }
        
        int ret = s[index].back();
        s[index].pop_back();
        if (s[index].empty()) s.erase(s.begin() + index);
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

