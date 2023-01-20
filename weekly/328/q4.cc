class Solution {
    using ll = long long;
public:
    ll maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector g = vector(n, vector<int>{});
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
    
        ll ans = 0;
        function<pair<ll, ll>(int, int)> dfs;
        dfs = [&](int x, int p) {
            ll msum1 = price[x], msum2 = 0, c = price[x];
            for (auto y : g[x]) {
                if (y == p) continue;
                auto [s1, s2] = dfs(y, x);
                ans = max({ans, msum1 + s2, msum2 + s1});
                msum1 = max(msum1, s1 + c);
                msum2 = max(msum2, s2 + c);
            }
            return make_pair(msum1, msum2);
        };
        dfs(0, -1);

        return ans;
    }
};
