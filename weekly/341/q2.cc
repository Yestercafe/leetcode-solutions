class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxx = -1, ans = INT_MAX;
        for (auto d : divisors) {
            int s = 0;
            for (auto n : nums) {
                if (n % d == 0) ++s;
            }
            if (maxx < s) {
                maxx = max(maxx, s);
                ans = d;
            } else if (maxx == s) {
                ans = min(ans, d);
            }
        }
        return ans;
    }
};

