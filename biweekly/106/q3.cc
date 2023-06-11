class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') nums[i] -= d;
            else nums[i] += d;
        }
        sort(nums.begin(), nums.end(), greater<>{});
        long long ans = 0;
        constexpr int MOD = 1e9 + 7;
        for (int i = 0, f = n - 1; i < n; ++i, f -= 2) {
            auto F = 1LL * f * nums[i];
            if (F < 0) {
                F = MOD + F % MOD;
            }
            ans = (ans + 1LL * F) % MOD;
        }
        return ans % MOD;
    }
};

