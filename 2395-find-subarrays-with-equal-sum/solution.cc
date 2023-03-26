class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (2 <= ++m[nums[i] + nums[i + 1]]) {
                return true;
            }
        }
        return false;
    }
};

