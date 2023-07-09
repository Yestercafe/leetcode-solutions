class Solution {
    using i64 = long long;
public:
    int threeSumClosest(vector<int>& nums, int target) {
        i64 ans = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            auto sum = [&]() {
                return nums[l] + nums[r] + nums[i];
            };
            while (l < i && i < r) {
                i64 s = sum();
                if (_abs(s - target) < _abs(ans - target)) ans = s;
                if (ans == target) return ans;
                if (s < target) ++l;
                if (s > target) --r;
            }
        }
        return ans;
    }
    static i64 _abs(i64 x) { return x < 0 ? -x : x; }
};

