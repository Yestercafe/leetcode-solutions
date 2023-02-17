class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector pr(n, vector(m + 1, 0)), pc(m, vector(n + 1, 0));
        for (int r = 0; r < n; ++r) {
            for (int i = 0; i < m; ++i) {
                pr[r][i + 1] = pr[r][i] + grid[r][i];
            }
        }
        for (int c = 0; c < m; ++c) {
            for (int i = 0; i < n; ++i) {
                pc[c][i + 1] = pc[c][i] + grid[i][c];
            }
        }

        for (auto& v: pr) {
            for (auto a : v) {
                cout << a << ' ';
            } 
            cout << endl;
        }

        for (auto& v: pc) {
            for (auto a : v) {
                cout << a << ' ';
            }
            cout << endl;
        }

        for (int l = min(n, m); l > 0; --l) {
            for (int x = 0; x <= n - l; ++x) {
                for (int y = 0; y <= m - l; ++y) {
                    if (pr[x][y + l] - pr[x][y] == l &&
                        pr[x + l - 1][y + l] - pr[x + l - 1][y] == l &&
                        pc[y][x + l] - pc[y][x] == l &&
                        pc[y + l - 1][x + l] - pc[y + l - 1][x] == l) {
                            return l * l;
                        }
                }
            }
        }

        return 0;
    }
};

