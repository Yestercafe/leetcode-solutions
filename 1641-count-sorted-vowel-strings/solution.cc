class Solution {
public:
    int countVowelStrings(int n) {
        vector f(n, vector(5, 0));
        for (int i = 0; i < 5; ++i) f[0][i] = 1;
        for (int i = 1; i < n; ++i) {
            for (int c = 0; c < 5; ++c) {
                for (int cc = 0; cc <= c; ++cc) {
                    f[i][c] += f[i - 1][cc];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 5; ++i) ans += f.back()[i];
        return ans;
    }
};

