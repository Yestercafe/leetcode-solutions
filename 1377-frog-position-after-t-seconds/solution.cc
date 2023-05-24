class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector g(n, vector<int>{});
        for (auto& e : edges) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        --target;

        vector prob(n, 0.);
        vector vis(n, false);
        double ans = 0;
        function<void(int, int)> dfs = [&](int i, int sec) {
            vis[i] = true;
            if (sec == 0) {
                if (i == target) {
                    ans += prob[target];
                }
                vis[i] = false;
                return;
            }
            int reachable_cnt = count_if(g[i].begin(), g[i].end(), [&](int nxt) { return !vis[nxt]; });
            if (reachable_cnt == 0) {
                if (i == target) {
                    ans += prob[target];
                }
                vis[i] = false;
                return;
            }
            double ratio = prob[i] / reachable_cnt;
            for (auto nxt : g[i]) {
                if (vis[nxt]) continue;
                prob[nxt] = ratio;
                dfs(nxt, sec - 1);
            }
            vis[i] = false;
        };

        prob[0] = 1.;
        dfs(0, t);

        return ans;
    }
};

