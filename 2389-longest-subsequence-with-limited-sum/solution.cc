class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }
        int m = queries.size();
        vector ans(m, 0);
        for (int i = 0; i < m; ++i) {
            ans[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        }
        return ans;
    }
};

