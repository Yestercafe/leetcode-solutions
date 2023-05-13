class Solution {
    using i64 = long long;
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<i64> pf(n + 1), sf(n + 1);
        for (int i = 0; i < n; ++i) {
            pf[i + 1] = (1LL * pf[i]) | nums[i];
        }
        for (int i = n; i > 0; --i) {
            sf[i - 1] = (1LL * sf[i]) | nums[i - 1];
        }
        
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, pf[i] | ((1LL * nums[i]) << k) | sf[i + 1]);
        }
        return ans;
    }
};

