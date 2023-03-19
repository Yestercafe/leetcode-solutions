class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int dir[][2] = {1, 2, -1, 2, 1, -2, -1, -2, 2, 1, -2, 1, 2, -1, -2, -1};
        int n = grid.size();
        
        if (grid[0][0] != 0) return false;
        int x = 0, y = 0;
        
        int n2 = n * n;
        for (int i = 0; i < n2 - 1; ++i) {
            cout << i << endl;
            int nxt = i + 1;
            int tx = -1, ty = -1;
            for (int d = 0; d < 8; ++d) {
                int nx = x + dir[d][0], ny = y + dir[d][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (grid[nx][ny] == nxt) {
                    tx = nx;
                    ty = ny;
                    break;
                }
            }
            if (tx < 0) return false;
            x = tx;
            y = ty;
        }
        return true;
    }
};

