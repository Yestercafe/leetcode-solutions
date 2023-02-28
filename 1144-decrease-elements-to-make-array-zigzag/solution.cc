class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int s1 = 0, s2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {
            int m1 = INT_MAX, m2 = INT_MAX;
            if (i - 1 >= 0) {
                m1 = min(m1, nums[i - 1]);
            }
            if (i + 1 < n) {
                m1 = min(m1, nums[i + 1]);
                m2 = min(m2, nums[i]);
            }
            if (i + 2 < n) {
                m2 = min(m2, nums[i + 2]);
            }

            if (m1 <= nums[i]) s1 += nums[i] - m1 + 1;
            if (i + 1 < n && m2 <= nums[i + 1]) s2 += nums[i + 1] - m2 + 1;
        }
        return min(s1, s2);
    }
};

