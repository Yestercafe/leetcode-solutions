class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector f(n, vector(n, 0));
        for (int d = 2; d < n; ++d) {
            for (int i = 0; i + d < n; ++i) {
                int j = i + d;
                f[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return f[0][n - 1];
    }
};

