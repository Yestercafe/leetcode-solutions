class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int t) {
            int d = k - path.size();
            if (t < 0 || t > (i + i - d + 1) * d / 2) {
                return ;
            }
            if (path.size() == k/* && path[0] + path[1] + path[2] == n*/) {
                ans.push_back(path);
                return ;
            }

            for (int j = i; j >= d; --j) {
                path.push_back(j);
                dfs(j - 1, t - j);
                path.pop_back();
            }
        };
        dfs(9, n);

        return ans;
    }
};

