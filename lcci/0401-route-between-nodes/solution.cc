class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> g(n);
        for (auto& e : graph) {
            g[e[0]].push_back(e[1]);
        }

        vector<bool> vis(n);

        deque<int> q;
        q.push_back(start);
        vis[start] = true;
        while (!q.empty()) {
            auto f = q.front();
            q.pop_front();
            if (f == target) return true;
            for (auto nxt : g[f]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push_back(nxt);
            }
        }

        return false;
    }
};

