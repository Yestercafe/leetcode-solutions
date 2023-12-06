class MinStack {
    vector<int> inner;
    vector<int> mono;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        inner.push_back(x);
        if (mono.empty() || mono.back() >= x) {
            mono.push_back(x);
        }
    }
    
    void pop() {
        if (inner.empty()) return;
        auto back = inner.back();
        inner.pop_back();
        if (!mono.empty() && mono.back() == back) {
            mono.pop_back();
        }
    }
    
    int top() {
        return inner.back();
    }
    
    int getMin() {
        return mono.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

