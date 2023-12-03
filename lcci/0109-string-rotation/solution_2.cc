class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n != m) return false;
        if (n == 0) return true;
        for (int sp = 0; sp < n; ++sp) {
            bool brk = false;
            for (int i = 0; i < n; ++i) {
                if (s1[i] != s2[(i + sp) % n]) {
                    brk = true;
                    break;
                }
            }
            if (!brk) {
                return true;
            }
        }
        return false;
    }
};

