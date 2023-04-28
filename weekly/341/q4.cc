classj Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g;
        g.resize(n);
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis;
        vector<int> factors(n);
        vector<int> path;
        function<bool(int, int)> dfs = [&](int s, int e) {
            path.push_back(s);
            vis[s] = true;
            if (s == e) {
                for (auto p : path) ++factors[p];
                path.clear();
                return true;
            }
            
            bool ret = false;
            for (auto nxt : g[s]) {
                if (vis[nxt]) continue;
                ret |= dfs(nxt, e);
                if (ret) return ret;
            }
            path.pop_back();
            return ret;
        };
        
        for (auto t : trips) {
            auto s = t[0], e = t[1];
            vis.clear();
            vis.resize(n);
            dfs(s, e);
        }
        
        for (auto a : factors) {
            cout << a << ' ';
        }
        cout << endl;
        
        int ans = INT_MAX;
        
        function<int(int)> sol = [&](int s) {
            vis[s] = true;
            
            int ans1 = price[s] * factors[s];
            for (auto nxt : g[s]) {
                if (vis[nxt]) continue;
                ans1 += sol(nxt);
            }
            
            int ans2 = price[s] / 2 * factors[s];
            
            vector<bool> k(n);
            for (auto nxt : g[s]) {
                if (vis[nxt]) continue;
                vis[nxt] = k[nxt] = true;
                ans2 += price[nxt] * factors[nxt];
                for (auto nnxt : g[nxt]) {
                    if (vis[nnxt]) continue;
                    ans2 += sol(nnxt);
                }
            }
            for (auto nxt : g[s]) {
                if (k[nxt]) vis[nxt] = false;
            }
            
            vis[s] = false;
            return min(ans1, ans2);
        };
        
        vis.clear();
        vis.resize(n);
        
        for (int i = 0; i < n; ++i) {
            vis.clear();
            vis.resize(n);
            auto s = sol(i);
            ans = min(s, ans);
        }
        
        return ans;
    }
};

