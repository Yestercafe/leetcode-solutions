class SortedStack {
    stack<int> s;
    stack<int> t;

    void trans(stack<int>& s, stack<int>& t) {
        auto top = s.top();
        s.pop();
        t.push(top);
    }
public:
    SortedStack() {

    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            return;
        }
        while (!s.empty() && s.top() < val) {
            trans(s, t);
        }
        s.push(val);
        while (!t.empty()) {
            trans(t, s);
        }
    }
    
    void pop() {
        if (s.empty()) return;
        s.pop();
    }
    
    int peek() {
        if (s.empty()) return -1;
        return s.top();
    }
    
    bool isEmpty() {
        return s.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

