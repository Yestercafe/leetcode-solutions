class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (auto a : nums) {
            int p = lower - a;
            int q = upper - a;
            int pi = lower_bound(nums.begin(), nums.end(), p) - nums.begin();
            int qi = lower_bound(nums.begin(), nums.end(), q + 1) - nums.begin() - 1;
            // cout << qi << ' ' << pi << endl;
            
            if (qi >= pi) {
                ans += qi - pi + 1;
                if (p <= a && a <= q) ans--;
            }
        }
        return ans / 2;
    }
};

