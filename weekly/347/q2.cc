int _abs(int a) { return a < 0 ? -a : a; }

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                set<int> s, t;
                int dif = j - i;
                
                for (int k = i - 1; k >= 0 && dif + k >= 0; --k) {
                    s.insert(grid[k][dif + k]);
                }
                for (int k = i + 1; k < n && dif + k < m; ++k) {
                    t.insert(grid[k][dif + k]);
                }
                
                ans[i][j] = _abs(s.size() - t.size());
            }
        }
        return ans;
    }
};

