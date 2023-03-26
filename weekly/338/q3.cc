class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& qs) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        int m = qs.size();
        vector<long long> ans(m);
        for (int i = 0; i < m; ++i) {
            auto fnd = lower_bound(nums.begin(), nums.end(), qs[i]);
            if (fnd == nums.end()) {
                ans[i] = (long long) n * qs[i] - pref[n];
            } else {
                ans[i] = (pref[n] - pref[fnd - nums.begin()] - (n - (fnd - nums.begin())) * (long long) qs[i]) + ((long long) qs[i] * (fnd - nums.begin()) - pref[fnd - nums.begin()]);
            }
        }
        return ans;
    }
};

