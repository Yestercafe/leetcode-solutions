class Solution {
    constexpr static int dir[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        deque<pair<int, int>> q;
        q.push_back({sr, sc});
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            image[x][y] = newColor;
            for (int d = 0; d < 4; ++d) {
                auto nx = x + dir[d][0], ny = y + dir[d][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || image[nx][ny] != oldColor) {
                    continue;
                }
                q.push_back({nx, ny});
            }
        }
        return image;
    }
};

