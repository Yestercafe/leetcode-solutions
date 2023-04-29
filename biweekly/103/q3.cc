constexpr int dir[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector vis(n, vector(m, false));
        int ans = 0;
        auto bfs = [&](int i, int j) {
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = true;
            int ret = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                ret += grid[x][y];
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dir[d][0], ny = y + dir[d][1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || grid[nx][ny] == 0) continue;
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
            return ret;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0 || vis[i][j]) continue;
                ans = max(ans, bfs(i, j));
            }
        }
        return ans;
    }
};

