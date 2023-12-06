class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int n = nums.size();
        function<void(int, vector<int>&)> dfs = [&](int i, vector<int>& path) {
            if (i == n) return;
            dfs(i + 1, path);
            path.push_back(nums[i]);
            ans.emplace_back(path);
            dfs(i + 1, path);
            path.pop_back();
        };
        vector<int> v;
        dfs(0, v);
        return ans;
    }
};

