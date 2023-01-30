class Solution {
    using ll = long long;
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector gr(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 2; i >= 0; --i) {
            copy(gr[i + 1].begin(), gr[i + 1].end(), gr[i].begin());
            for (int j = nums[i + 1] - 1; j >= 1; --j) {
                ++gr[i][j];
            }
        }

        ll ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (nums[i] > nums[j]) {
                    int l_less = nums[j] - (n - 1 - i - gr[i][nums[j]]);
                    int r_greater = gr[j][nums[i]];
                    ans += l_less * r_greater;
                }
            }
        }
        return ans;
    }
};

