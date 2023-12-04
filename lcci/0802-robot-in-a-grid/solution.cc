class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid.front().front() == 1) return {};
        vector<vector<int>> ans;
        ans.reserve(n + m - 1);
        
        vector f(n + 1, vector(m + 1, -1));
        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= m; ++y) {
                if (x == 1 && y == 1) {
                    f[x][y] = 1;
                    continue;
                }
                if (obstacleGrid[x - 1][y - 1] || (f[x][y - 1] < 0 && f[x - 1][y] < 0)) {
                    f[x][y] = -1;
                } else {
                    f[x][y] = 1 + max(f[x - 1][y], f[x][y - 1]);
                }
            }
        }
        
        if (f.back().back() < 0) {
            return {};
        }
        int c = f.back().back(), x = n, y = m;
        ans.push_back({x - 1, y - 1});
        while (c != 1) {
            cout << c << endl;
            if (x - 1 > 0 && f[x - 1][y] == c - 1) {
                --x;
                --c;
                ans.push_back({x - 1, y - 1});
            }
            else if (y - 1 > 0 && f[x][y - 1] == c - 1) {
                --y;
                --c;
                ans.push_back({x - 1, y - 1});
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

