class Solution {
    vector<vector<int>> g;
    vector<vector<int>> c;
    int n;
    void bfs(int start) {
        vector<bool> vis(n);
        deque<int> q;
        q.push_back(start);
        vis[start] = true;
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto top = q.front();
                q.pop_front();
                c[top].push_back(depth);
                for (auto nxt : g[top]) {
                    if (vis[nxt]) continue;
                    vis[nxt] = true;
                    q.push_back(nxt);
                }
            }
            ++depth;
        }
    }
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        n = coins.size();
        g = vector<vector<int>>(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        c = vector<vector<int>>(n);
        for (int i = 0; i < n; ++i) {
            if (coins[i] == 1) {
                bfs(i);
            }
        }
        
        int ans = INT_MAX;
        int nn = c[0].size();
        if (nn == 0) return 0;
        for (int i = 0; i < n; ++i) {
            sort(c[i].begin(), c[i].end());
            int local_ans = 0;
            if (c[i].back() <= 2) return 0;
            for (int j = 0; j < nn; ++j) {
                if (c[i][j] > 2) {
                    local_ans += 2 * (c[i][j] - 2);
                }
            }
            
            ans = min(ans, local_ans);
        }
        return ans;
    }
};

