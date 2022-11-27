class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        map<int, int> rc;
        int pk = find(nums.begin(), nums.end(), k) - nums.begin();
        int lsc = 0, grc = 0;
        for (int d = 1; pk + d < n; ++d) {
            if (nums[pk + d] < k) {
                ++lsc;
            } else {
                ++grc;
            }
            if (lsc == grc || lsc + 1 == grc) ++ans;
            ++rc[lsc - grc];
        }
        
        lsc = grc = 0;
        for (int d = 1; pk - d >= 0; ++d) {
            if (nums[pk - d] < k) {
                ++lsc;
            } else {
                ++grc;
            }
            if (lsc == grc || lsc + 1 == grc) ++ans;
            ans += rc[grc - lsc] + rc[grc - lsc - 1];
        }
        
        return ans;
    }
};
