constexpr int dir[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
class Solution {
    struct Node {
        int x, y;
        int v;
    };
public:
    int minimumCost(vector<int>& start, vector<int>& tt, vector<vector<int>>& sr) {
        int n = tt[0] - start[0], m = tt[1] - start[1];
        pair<int, int> target {tt[0] - start[0], tt[1] - start[1]};
        map<pair<int, int>, vector<Node>> r;
        for (auto& v: sr) {
            r[make_pair(v[0] - start[0], v[1] - start[1])].push_back({v[2] - start[0], v[3] - start[1], v[4]});
        }
        vector vis(n + 1, vector(m + 1, INT_MAX));
        vis[0][0] = 0;
        queue<Node> q;
        q.push({0, 0, 0});
        int ans = INT_MAX;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto fr = q.front();
                if (fr.x == target.first && fr.y == target.second) {
                    ans = min(ans, fr.v);
                }
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = dir[d][0] + fr.x, ny = dir[d][1] + fr.y;
                    if (nx < 0 || nx > n || ny < 0 || ny > m || fr.v + 1 > n + m) continue;
                    if (vis[nx][ny] > fr.v + 1) {
                        vis[nx][ny] = fr.v + 1;
                        q.push({nx, ny, fr.v + 1});
                    }
                }
                
                auto frxy = make_pair(fr.x, fr.y);
                for (auto nxt : r[frxy]) {
                    auto nx = make_pair(nxt.x, nxt.y);
                    if (abs(fr.x - nx.first) + abs(fr.y - nx.second) <= nxt.v) continue;
                    if (fr.v + nxt.v <= n + m  && vis[nxt.x][nxt.y] > fr.v + nxt.v) {
                        vis[nxt.x][nxt.y] = fr.v + nxt.v;
                        q.push({nxt.x, nxt.y, fr.v + nxt.v});
                    }
                }
            }
        }
        return ans;
    }
};

