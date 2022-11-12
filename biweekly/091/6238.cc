class Solution {
    constexpr static int MOD = 1e9 + 7;
public:
    int countGoodStrings(int l, int h, int z, int o) {
        vector<int> f(100005, 0);
        f[0] = 1;
        int sum = 0;
        for (int i = 1; i <= h; ++i) {
            if (i >= z) f[i] = (f[i] + f[i - z]) % MOD;
            if (i >= o) f[i] = (f[i] + f[i - o]) % MOD;
            if (i >= l) sum = (sum + f[i]) % MOD;
        }
        return sum;
    }
};

