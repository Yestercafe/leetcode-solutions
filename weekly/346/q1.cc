class Solution {
public:
    int minLength(string s) {
        int p1, p2;
        while ((p1 = s.find("AB")) != s.npos || (p2 = s.find("CD")) != s.npos) {
            if (p1 != s.npos) s.erase(s.begin() + p1, s.begin() + p1 + 2);
            else s.erase(s.begin() + p2, s.begin() + p2 + 2);
        }
        return s.size();
    }
};

