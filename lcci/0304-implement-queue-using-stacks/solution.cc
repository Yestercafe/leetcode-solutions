class MyQueue {
    stack<int> a, b;
    void transfer(stack<int>& p, stack<int>& q) {
        while (!p.empty()) {
            int top = p.top();
            p.pop();
            q.push(top);
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (a.empty()) return -1;
        transfer(a, b);
        auto ret = b.top();
        b.pop();
        transfer(b, a);
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (a.empty()) return -1;
        transfer(a, b);
        auto ret = b.top();
        transfer(b, a);
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

