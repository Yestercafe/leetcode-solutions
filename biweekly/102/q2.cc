class Solution {
    using i64 = long long;
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<i64> ans(n + 1);
        i64 end = 0;
        int maxx = nums[0];
        for (int i = 0; i < n; ++i) {
            maxx = max(maxx, nums[i]);
            end = nums[i] + maxx;
            ans[i + 1] = end + ans[i];
        }
        
        ans.erase(ans.begin());
        return ans;
    }
};

