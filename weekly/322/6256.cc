class Solution {
    vector<vector<int>> g;
    int n;
    vector<int> color;
    vector<int> nodes;
    vector<bool> vis;

    int bfs(int s) {
        for (auto b : vis) b = false;
        queue<int> q;
        q.push(s);
        vis[s] = true;
        int depth = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto t = q.front();
                q.pop();
                for (auto& nxt : g[t]) {
                    if (vis[nxt]) continue;
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
            ++depth;
        }
        return depth;
    }

    bool isBipartite(int i, int c) {
        nodes.push_back(i);
        color[i] = c;
        for (auto& nxt : g[i]) {
            if (color[nxt] == c || (color[nxt] == 0 && !isBipartite(nxt, 3 ^ c))) {
                return false;
            }
        }
        return true;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.assign(n, {});
        color.assign(n, 0);
        for (auto& e : edges) {
            g[e[0] - 1].push_back(e[1] - 1);
            g[e[1] - 1].push_back(e[0] - 1);
        }

        int ans = 0;
        vis.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) continue;
            nodes.clear();
            if (!isBipartite(i, 1)) {
                return -1;
            }
            
            int partial = 0;
            for (auto& n : nodes) {
                partial = max(bfs(n), partial);
            }
            ans += partial;
        }

        return ans;
    }
};

