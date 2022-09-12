class Solution {
public:
    int specialArray(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int r = -1;
        for (int i = 0; i < N; ++i) {
            if (nums[i] >= N - i) {
                if (i != 0 && nums[i - 1] >= N - i) {
                    continue;
                }
                r = N - i;
                break;
            }
        }
        return r;
    }
};

