class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        deque<int> s;
        auto itr = pushed.begin();
        while (!popped.empty()) {
            if (!s.empty() && s.back() == popped.front()) {
                popped.erase(popped.begin());
                s.pop_back();
            } else if (!s.empty() && itr == pushed.end()) {
                return false;
            } else {
                if (itr != pushed.end()) {
                    s.push_back(*itr);
                    ++itr;
                }
            }
        }
        if (s.empty()) {
            return true;
        }
        return false;
    }
};

