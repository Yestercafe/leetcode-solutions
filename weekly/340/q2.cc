class Solution {
    using i64 = long long;
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<i64> ans(n);
        unordered_map<int, pair<i64, int>> pr, su;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            su[a].first += i;
            su[a].second++;
        }
        
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            su[a].second--;
            su[a].first -= i;
            
            auto [s1, c1] = pr[a];
            auto [s2, c2] = su[a];
            ans[i] = 1LL * c1 * i - s1 + s2 - 1LL * c2 * i;
            
            pr[a].first += i;
            pr[a].second++;
        }
        
        return ans;
    }
};

