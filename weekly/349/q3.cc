class Solution {
    using i64 = long long;
public:
    long long minCost(vector<int>& nums, int x) {
        i64 ans = INT64_MAX;
        int n = nums.size();
        vector<int> cost(n, INT_MAX);
    
        i64 init = 0;
        for (int d = 0; d < n; ++d, init += 1LL * x) {
            i64 sum = init;
            for (int i = 0; i < n; ++i) {
                cost[i] = min(nums[(i + d) % n], cost[i]);
                sum += 1LL * cost[i];
            }
            ans = min(ans, sum);
        }
        
        return ans;
    }
};

