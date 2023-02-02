class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector ans(n, -1);
        vector rg(n, vector<int>{});
        vector bg(n, vector<int>{});
        for (auto& v : re) rg[v.front()].push_back(v.back());
        for (auto& v : be) bg[v.front()].push_back(v.back());

        auto solve = [&](int times) {
            queue<int> q;
            vector<bool> vis(2 * n, false);
            q.push(0);
            vis[0] = vis[n] = true;
            ans[0] = 0;
            
            int depth = 0;
            while (!q.empty()) {
                int s = q.size();
                while (s--) {
                    auto t = q.front();
                    // cout << "depth = " << depth << ", t = " << t << endl;
                    q.pop();
                    ans[t] = (ans[t] < 0 ? depth : min(ans[t], depth));
                    if (depth % 2 == times) {
                        for (auto nxt : rg[t]) {
                            if (vis[nxt]) continue;
                            vis[nxt] = true;
                            q.push(nxt);
                        }
                    } else {
                        for (auto nxt : bg[t]) {
                            if (vis[nxt + n]) continue;
                            vis[nxt + n] = true;
                            q.push(nxt);
                        }
                    }
                }
                ++depth;
            }
        };

        solve(0);
        solve(1);

        return ans;
    }
};

