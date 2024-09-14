const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector dp(n, vector(m, 114514));
        dp[0][0] = grid[0][0];
        while (true) {
            bool fixpoint = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int old_ij = dp[i][j];
                    for (int r = 0; r < 4; ++r) {
                        int ni = i + dir[r][0], nj = j + dir[r][1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            if (dp[i][j] > dp[ni][nj] + grid[i][j]) {
                                dp[i][j] = dp[ni][nj] + grid[i][j];
                                fixpoint = false;
                            }
                        }
                    }
                    
                }
            }

            if (fixpoint) {
                break;
            }
        }

        return health > dp[n - 1][m - 1];
    }
};

