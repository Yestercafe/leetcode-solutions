class Solution {
    using i64 = long long;
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int i = 0, k = 0;
        i64 ans = 0;
        int diff = 0;
        for (; k < n; ++k) {
            ans = max(ans, 1LL * diff * nums[k]);
            diff = max(diff, nums[i] - nums[k]);
            if (nums[i] <= nums[k]) {
                i = k;
            }
        }

        return ans;
    }
};
