class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int)> dfs = [&](int i) {
            ans.push_back(path);
            if (i == n) {
                return ;
            }

            for (int j = i; j < n; ++j) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);

        return ans;
    }
};

