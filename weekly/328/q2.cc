class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector d(n + 2, vector(n + 2, 0)), m(n, vector(n, 0));
        for (auto& v : queries) {
            int x1 = v[0] + 1, y1 = v[1] + 1, x2 = v[2] + 1, y2 = v[3] + 1;
            d[x1][y1] += 1;
            d[x1][y2 + 1] -= 1;
            d[x2 + 1][y1] -= 1;
            d[x2 + 1][y2 + 1] += 1;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
                m[i - 1][j - 1] = d[i][j];
            }
        }
        return m;
    }
};
