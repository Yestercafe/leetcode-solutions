class Solution {
    using i64 = long long;
public:
    int sumOfPower(vector<int>& nums) {
        i64 ans = 0;
        constexpr i64 MOD = 1e9 + 7;
        if (nums.size() == 1) return ((1LL * nums[0] * nums[0]) % MOD * nums[0]) % MOD;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<i64> pf(n);
        vector<i64> p(n);
        pf[0] = nums[0];
        pf[1] = nums[1] + nums[0];
        p[1] = nums[0];
        for (int i = 2; i < n; ++i) {
            p[i] = ((p[i - 1] * 2) % MOD + nums[i - 1]);
            pf[i] = (((nums[i] + nums[i - 1]) % MOD) + 2 * p[i - 1]) % MOD;
        }
        
        for (int i = 0; i < n; ++i) {
            ans = (ans + ((1LL * nums[i] * nums[i]) % MOD * pf[i]) % MOD) % MOD;
        }
        
        return ans % MOD;
    }
};

