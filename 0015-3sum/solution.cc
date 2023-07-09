class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            auto sum = [&]() {
                return nums[l] + nums[r] + nums[i];
            };
            while (l < i && i < r) {
                int s = sum();
                if (s == 0) {
                    ans.push_back({nums[l], nums[r], nums[i]});
                }
                if (s <= 0) do {
                    ++l;
                } while (l < i && nums[l - 1] == nums[l]);
                if (s >= 0) do {
                    --r;
                } while (i < r && nums[r] == nums[r + 1]);
            }
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                if (-2 * nums[i] >= nums[i] && binary_search(nums.begin() + i + 2, nums.end(), -2 * nums[i])) {
                    ans.push_back({nums[i], nums[i], -2 * nums[i]});
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) ++i;
        }
        return ans;
    }
};

