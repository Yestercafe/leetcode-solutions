class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2) return -1;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i;
        for (i = 1; i < n; ++i) {
            if (nums[i] == nums.back()) {
                i = -1;
                break;
            }
            if (nums[i] != nums.front()) {
                break;
            }
        }
        if (i == -1) { return -1; }
        return nums[i];
    }
};

