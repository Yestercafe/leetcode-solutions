class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int)> dfs = [&](int i) {
            if (path.size() == k) {
                ans.push_back(path);
                return ;
            }

            for (int j = i; j >= k - path.size(); --j) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };
        dfs(n);

        return ans;
    }
};

