class Solution {
    using i64 = long long;
    static constexpr i64 MOD = 1000000007;
public:
    int waysToStep(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        vector<i64> f(n + 1);
        f[1] = 1, f[2] = 2, f[3] = 4;
        for (int i = 4; i <= n; ++i) {
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
        }
        return (int)f.back();
    }
};

