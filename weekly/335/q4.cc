class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        constexpr int MOD = 1e9 + 7;
        int n = types.size();
        vector f(n + 1, vector(target + 1, 0));
        for (int i = 0; i < n + 1; ++i) f[i][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                f[i][j] = f[i - 1][j];
                for (int c = 1; c <= types[i-1][0] && j - c * types[i-1][1] >= 0; ++c) {
                    f[i][j] = (f[i][j] + f[i - 1][j - c * types[i-1][1]]) % MOD;
                }
            }
        }
        return f[n][target];
    }
};

