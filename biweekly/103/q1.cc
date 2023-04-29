class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        ans = k * nums.back();
        for (int i = 0; i < k; ++i) {
            ans += i;
        }
        return ans;
    }
};

