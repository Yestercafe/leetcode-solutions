class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) return 0;
        sort(nums.begin(), nums.end());
        return min({nums.back() - nums[2], *(nums.end() - 3) - nums[0], *(nums.end() - 2) - nums[1]});
    }
};

