class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                ret.push_back(nums[i]);
            }
        }
        if (nums.back() != 0) ret.push_back(nums.back());
        while (ret.size() < n) ret.push_back(0);
        return ret;
    }
};

