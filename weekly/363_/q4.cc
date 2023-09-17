class Solution {
    using i64 = long long;
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<i64> ans(n + 1);

        auto f = [&](int a) {
            i64 rem = 1;
            for (int factor = 2; factor <= a / factor; ++factor) {
                int factor_idx = 0;
                while (a % factor == 0) {
                    ++factor_idx;
                    a /= factor;
                }
                if (factor_idx % 2) rem *= factor;
            }
            return rem * a;
        };

        for (int i = 0; i < n; ++i) {
            ans[f(i + 1)] += nums[i];
        }

        return *max_element(ans.begin(), ans.end());
    }
};

