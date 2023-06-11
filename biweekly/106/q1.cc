class Solution {
public:
    bool isFascinating(int n) {
        auto s = to_string(n) + to_string(2*n) + to_string(3*n);
        set<char> c(s.begin(), s.end());
        return s.size() == 9 && c.size() == 9 && c.count('0') == 0;
    }
};

