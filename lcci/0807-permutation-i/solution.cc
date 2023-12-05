class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        int n = s.length();
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        function<void(vector<bool>&, vector<int>&, int)> dfs = [&](vector<bool>& vis, vector<int>& path, int remain) {
            if (remain == 0) {
                string t(n, '\0');
                for (int i = 0; i < n; ++i) {
                    t[i] = s[path[i]];
                }
                ans.push_back(move(t));
            }
            for (int i = 0; i < n; ++i) {
                if (vis[i]) continue;
                vis[i] = true;
                path.push_back(i);
                dfs(vis, path, remain - 1);
                path.pop_back();
                vis[i] = false;
            }
        };

        vector<bool> vis(n, false);
        vector<int> path{};
        dfs(vis, path, n);
        return ans;
    }
};

