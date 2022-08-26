class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        int ans = -99, maxx = nums.front() - 1;
        for (int i = 1; i < N; ++i) {
            ans = max(ans, (nums[i] - 1) * maxx);
            maxx = max(maxx, nums[i] - 1);
        }
        return ans;
    }
};
