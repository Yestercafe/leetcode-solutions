class Solution {
    struct C { int x, y; };
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector f(n, vector(m, -1));
        vector vis(n, vector(m, false));
        queue<C> q;
        q.push({0, 0});
        int step = 1;
        vis[0][0] = true; 
        vector<int> far_x(m), far_y(n);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                f[x][y] = step;
                for (int nx = max(x + 1, far_x[y] + 1); nx <= x + grid[x][y] && nx < n; ++nx) {
                    if (!vis[nx][y]) {
                        far_x[y] = nx;
                        q.push({nx, y});
                        vis[nx][y] = true;
                    }
                }
                for (int ny = max(y + 1, far_y[x] + 1); ny <= y + grid[x][y] && ny < m; ++ny) {
                    if (!vis[x][ny]) {
                        far_y[x] = ny;
                        q.push({x, ny});
                        vis[x][ny] = true;
                    }
                }
            }
            ++step;
        }
        
        return f.back().back();
    }
};

