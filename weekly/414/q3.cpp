class Solution {
    using i64 = long long;
public:
    long long findMaximumScore(vector<int>& nums) {
        int len = nums.size();
        i64 ans = 0;
        int t = nums[0], pos = 0;
        for (int i = 1; i < len; ++i) {
            if (nums[i] > t) {
                ans += 1LL * (i - pos) * t;
                t = nums[i];
                pos = i;
            }
        }

        ans += 1LL * (len - 1 - pos) * t;

        return ans;
    }
};

