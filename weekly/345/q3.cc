class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector f(n, vector(m, 0));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            f[i][0] = 1;
        }
        
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                for (int p = max(0, i - 1); p <= min(i + 1, n - 1); ++p) {
                    if (grid[p][j - 1] < grid[i][j]) {
                        if (f[p][j - 1]) {
                            ans = f[i][j] = f[p][j - 1] + 1;
                            break;
                        }
                    }
                }
            }
        }
        
        return ans ? ans - 1 : 0;
    }
};

