class Solution {
    vector<vector<int>> g;
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        g.assign(n, {});
        for (auto& p : edges) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        
        int ans = -123456789;
        for (int i = 0; i < n; ++i) {
            int s = vals[i];
            sort(g[i].begin(), g[i].end(), [&](const int& a, const int& b) { return vals[a] > vals[b]; });
            for (int j = 0; j < g[i].size() && j < k && vals[g[i][j]] > 0; ++j) {
                s += vals[g[i][j]];
            }
            ans = max(ans, s);
        }
        return ans;
    }
};

