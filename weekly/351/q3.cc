class Solution {
    using i64 = long long;
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        constexpr int MOD = 1e9 + 7;
        vector<int> zcnt;
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                zcnt.push_back(cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        zcnt.push_back(cnt);
        
        int nz = zcnt.size();
        if (nz == 1) return 0;
        i64 ans = 1;
        for (int i = 1; i < nz - 1; ++i) {
            ans = (ans * (zcnt[i] + 1)) % MOD;
        }
        return ans;
    }
};

