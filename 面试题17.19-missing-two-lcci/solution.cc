class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        long long two_sum = 0, two_sumsq = 0;
        for (int a = 1; a <= n; ++a) {
            two_sum += a;
            two_sumsq += a * a;
        }
        
        for (auto& a : nums) {
            two_sum -= a;
            two_sumsq -= a * a;
        }
        
        int s = two_sum, t = two_sumsq;
        int x1 = (s + sqrt(-s * s + 2 * t)) / 2,
            x2 = (s - sqrt(-s * s + 2 * t)) / 2;
        
        return {x1, x2};
    }
};

