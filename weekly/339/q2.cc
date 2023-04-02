class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int m = 0;
        for (auto a : nums) {
            int c = ++cnt[a];
            m = max(m, c);
        }
        vector<vector<int>> ans(m);
        for (auto [a, c] : cnt) {
            for (int i = 0; i < c; ++i) {
                ans[i].push_back(a);
            }
        }
        return ans;
    }
};

