class Solution {
public:
    bool checkOnesSegment(string s) {
        return count(s.begin(), unique(s.begin(), s.end()), '1') < 2;
    }
};

