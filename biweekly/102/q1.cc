class Solutijon {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int maxx = -1;
            for (int j = 0; j < n; ++j) {
                maxx = max(maxx, (int) to_string(grid[j][i]).size());
            }
            ans[i] = maxx;
        }
        return ans;
    }
};

