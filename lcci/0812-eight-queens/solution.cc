class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        function<void(vector<string>&, int)> dfs = [&](vector<string>& path, int r) {
            if (r == n) {
                ans.push_back(path);
                return;
            }

            for (int c = 0; c < n; ++c) {
                int failed = false;
                for (int rr = 0; rr < r; ++rr) {
                    if (path[rr][c] == 'Q') {
                        failed = true;
                        break;
                    }
                }
                if (failed) continue;
                for (int i = 1; i <= r; ++i) {
                    int rr = r - i;
                    int cc1 = c - i;
                    int cc2 = c + i;
                    if (cc1 >= 0 && path[rr][cc1] == 'Q') {
                        failed = true;
                        break;
                    }
                    if (cc2 < n && path[rr][cc2] == 'Q') {
                        failed = true;
                        break;
                    }
                }
                if (failed) continue;

                path[r][c] = 'Q';
                dfs(path, r + 1);
                path[r][c] = '.';
            }
        };

        vector<string> path(n);
        for (int i = 0; i < n; ++i) {
            path[i] = string(n, '.');
        }

        dfs(path, 0);

        return ans;
    }
};

