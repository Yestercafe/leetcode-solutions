kjclass Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        int n = s.length();
        int m = t.length();
        for (int d = 1 - m; d < n; ++d) {
            int i = max(d, 0);
            int j = max(0, -d);
            
            int p1 = i - 1, p2 = i - 1;
            while (i < n && j < m) {
                if (s[i] != t[j]) {
                    p1 = p2;
                    p2 = i;
                }
                ans += p2 - p1;
                ++i;
                ++j;
            }
        }
        return ans;
    }
};

