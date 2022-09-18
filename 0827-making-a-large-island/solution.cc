class Solution {
    vector<int> space;
    int n;
    static constexpr int direct[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    
    int bfs(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                q.emplace(i, j);
                int s = 1, nn = space.size();
                grid[i][j] = nn;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int d = 0; d < 4; ++d) {
                        int nx = x + direct[d][0], ny = y + direct[d][1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 1) {
                            continue;
                        }
                        grid[nx][ny] = nn;
                        ++s;
                        q.emplace(nx, ny);
                    }
                }
                space.push_back(s);
                m = max(m, s);
            }
        }
        return m;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        space.push_back(0);
        space.push_back(0);
        int r = bfs(grid);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int ss = 1;
                    set<int> t;
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + direct[d][0], nj = j + direct[d][1];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= n) {
                            continue;
                        }
                        t.insert(grid[ni][nj]);
                    }
                    
                    for (auto& a : t) {
                        ss += space[a];
                    }
                    
                    r = max(r, ss);
                }
            }
        }
        
        return r;
    }
};

