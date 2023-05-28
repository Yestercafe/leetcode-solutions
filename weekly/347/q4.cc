class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> maxr(n), maxc(m);
        vector<array<int, 3>> ps;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ps.push_back({mat[i][j], i, j});
            }
        }
        sort(ps.begin(), ps.end(), greater<>{});
        int ans = 0;
        int b = ps.size();
        vector<array<int, 3>> lazy;
        for (int i = 0; i < b; ++i) {
            auto& p = ps[i];
            auto a = p[0], x = p[1], y = p[2];
            auto q = 1 + max(maxr[x], maxc[y]);
            lazy.push_back({q, x, y});
            ans = max(ans, q);
            if (i + 1 == b || ps[i + 1][0] != a) {
                for (auto e : lazy) {
                    maxr[e[1]] = max(maxr[e[1]], e[0]);
                    maxc[e[2]] = max(maxc[e[2]], e[0]);
                }
                lazy.clear();
            }
        }
        return ans;
    }
};

