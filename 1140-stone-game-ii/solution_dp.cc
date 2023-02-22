class Solution {
public:
    int stoneGameII(vector<int>& p) {
        int n = p.size();
        vector f(n, vector(n + 1, 0));
        int suf = 0;
        for (int i = n - 1; i >= 0; --i) {
            suf += p[i];
            for (int m = 1; m < i / 2 + 2; ++m) {
                if (i + 2 * m >= n) {
                    f[i][m] = suf;
                } else {
                    int minn = INT_MAX;
                    int bound = min(1 + 2 * m, n - i);
                    for (int x = 1; x < bound; ++x) {
                        minn = min(minn, f[i + x][max(m, x)]);
                    }
                    f[i][m] = suf - minn;
                }
            }
        }
        return f[0][1];
    }
};

