struct P {
    int x, y;
    int t;
    P() = default;
    P(int x, int y, int t) : x{x}, y{y}, t{t} {}
    friend bool operator<(const P& lhs, const P& rhs) {
        return lhs.t > rhs.t;
    }
};

const int dir[][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int suf(int mt, int n) {
    if (n >= mt) return n + 1;
    if (mt % 2 == n % 2) {
        return mt + 1;
    } else {
        return mt;
    }
}

class Solution {
public:
    int minimumTime(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector f(n, vector<int>(m, INT_MAX));
        if (g[0][1] > 1 && g[1][0] > 1) return -1;
        priority_queue<P> pq;
        
        int ans = INT_MAX;
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            int front_t = pq.top().t;
            while (!pq.empty() && front_t == pq.top().t) {
                auto [x, y, _] = pq.top();
                pq.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dir[d][0], ny = y + dir[d][1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    int nt = suf(g[nx][ny], front_t);
                    if (nt >= f[nx][ny]) continue;
                    f[nx][ny] = nt;
                    if (nx == n - 1 && ny == m - 1) { ans = min(nt, ans); };
                    pq.emplace(nx, ny, nt);
                }
            }
        }
        return ans;
    }
};

