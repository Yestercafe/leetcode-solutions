class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        nums.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            nums.push_back(nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (is_sorted(nums.begin() + i, nums.begin() + n + i)) {
                return (n - i) % n;
            }
        }

        return -1;
    }
};
