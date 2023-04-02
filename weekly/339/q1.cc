class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool isOne = false;
                bool fail = false;
                int zs = 0, os = 0;
                for (int k = i; k <= j; ++k) {
                    if (s[k] == '0') {
                        if (isOne) {
                            fail = true;
                            break;
                        } else {
                            ++zs;
                        }
                    } else {
                        if (isOne) {
                            ++os;
                        } else {
                            isOne = true;
                            ++os;
                        }
                    }
                }
                if (!fail) {
                    ans = max(ans, 2 * min(os, zs));
                }
            }
        }
        return ans;
    }
};

