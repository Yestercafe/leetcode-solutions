class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n = s.size();
        int c0 = count(target.begin(), target.end(), '0'),
            c1 = n - c0;
        int d0 = count(s.begin(), s.end(), '0'),
            d1 = n - d0;
        if (c0 == d0) return true;
        if (c1 == 0 || d1 == 0) return false;
        return true;
    }
};

