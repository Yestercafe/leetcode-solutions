class Solution {
    using i64 = long long;
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n + 1), pref(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suff[i] = max(suff[i + 1], nums[i]);
        }
        
        i64 ans = 0;
        for (int i = 1; i < n; ++i) {
            pref[i] = max(pref[i - 1], nums[i - 1]);
            ans = max(ans, 1LL * (pref[i] - nums[i]) * suff[i + 1]);
        }

        return ans;
    }
};
