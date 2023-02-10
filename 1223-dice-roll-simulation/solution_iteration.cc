class Solution {
    static constexpr int MOD = 1e9 + 7;
    static int modadd(int a, int b) {
        return (a + b) % MOD;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        constexpr auto R = 6, M = 15;
        vector f(n, vector(R, vector(M, 0)));
        for (int j = 0; j < R; ++j) {
            for (int k = 0; k < M; ++k) {
                f[0][j][k] = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < R; ++j) {
                for (int k = 0; k < M; ++k) {
                    int sum = 0;
                    for (int p = 0; p < R; ++p) {
                        if (p != j) {
                            sum = modadd(sum, f[i - 1][p][rollMax[p] - 1]);
                        } else if (k > 0) {
                            sum = modadd(sum, f[i - 1][j][k - 1]);
                        }
                    }
                    f[i][j][k] = sum;
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < R; ++j) {
            ans = modadd(ans, f.back()[j][rollMax[j] - 1]);
        }
        return ans;
    }
};

