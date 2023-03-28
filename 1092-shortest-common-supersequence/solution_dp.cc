class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector f(n + 1, vector(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            f[i][0] = i;
        }
        for (int j = 1; j <= m; ++j) {
            f[0][j] = j;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                }
            }
        }

        string ans;
        ans.reserve(n + m);
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                ans.push_back(s[i - 1]);
                --i, --j;
            } else {
                if (f[i - 1][j] + 1 == f[i][j]) {
                    ans.push_back(s[i-- - 1]);
                } else {
                    ans.push_back(t[j-- - 1]);
                }
            }
        }

        reverse(ans.begin(), ans.end());
        if (i != 0) return s.substr(0, i) + ans;
        else return t.substr(0, j) + ans;
    }
};
