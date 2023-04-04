class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector pref(n + 1, 0);
        partial_sum(stones.begin(), stones.end(), pref.begin() + 1);
        vector f(n + 1, vector(n + 1, 114514));  // [i, j)

        for (int d = 0; d < k; ++d) {
            for (int i = 0; i + d <= n; ++i) {
                f[i][i + d] = 0;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n; ++j) {
                for (int m = i + 1; m < j; m += k - 1) {
                    f[i][j] = min(f[i][j], f[i][m] + f[m][j]);
                }
                if ((j - i - 1) % (k - 1) == 0) {
                    f[i][j] += pref[j] - pref[i];
                }
            }
        }

        return f[0][n];
    }
};

