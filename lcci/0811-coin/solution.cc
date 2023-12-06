class Solution {
    constexpr static const int MOD = 1e9 + 7;
public:
    int waysToChange(int n) {
        array<int, 4> cc {1, 5, 10, 25};
        array<vector<int>, 5> f;
        for (int i = 0; i < 5; ++i) {
            f[i] = vector<int>(n + 1);
            f[i][0] = 1;
        }
        for (int c = 1; c <= 4; ++c) {
            for (int ni = 1; ni <= n; ++ni) {
                f[c][ni] = f[c - 1][ni];
                if (ni - cc[c - 1] >= 0) {
                    f[c][ni] = (f[c][ni] + f[c][ni - cc[c - 1]]) % MOD;
                }
            }
        }
        return f.back().back();
    }
};

