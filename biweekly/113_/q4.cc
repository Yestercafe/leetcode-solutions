class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, bool>>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back({e[1], true});
            g[e[1]].push_back({e[0], false});
        }

        list<int> q;
        q.push_back(0);
        int f = 0;
        vector<int> vis(n);

        while (!q.empty()) {
            auto t = q.front();
            q.pop_front();
            vis[t] = true;
            for (auto [nxt, isSeq] : g[t]) {
                if (vis[nxt]) continue;
                q.push_back(nxt);
                f += !isSeq;
            }
        }

        fill(vis.begin(), vis.end(), false);
        vector<int> ans(n);
        ans[0] = f;
        q.push_back(0);
        while (!q.empty()) {
            auto t = q.front();
            q.pop_front();
            vis[t] = true;
            for (auto [nxt, isSeq] : g[t]) {
                if (vis[nxt]) continue;
                q.push_back(nxt);
                ans[nxt] = ans[t] + (isSeq ? +1 : -1);
            }
        }

        return ans;
    }
};

