class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        int n = nums.size(), m = nums[0].size();
        for (int i = 0; i < m; ++i) {
            int s = -1;
            for (int l = 0; l < n; ++l) {
                int maxx = -1, maxi;
                for (int i = 0; i < nums[l].size(); ++i) {
                    if (maxx < nums[l][i]) {
                        maxi = i;
                        maxx = nums[l][i];
                    }
                }
                s = max(s, maxx);
                nums[l].erase(nums[l].begin() + maxi);
            }
            ans += s;
        }
        return ans;
    }
};

