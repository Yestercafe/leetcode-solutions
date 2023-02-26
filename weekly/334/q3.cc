class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int h = n / 2;
        int i = h - 1, j = n - 1;
        int ans = 0;
        while (i != -1 && j != h - 1) {
            //cout << nums[i] << ' ' << ' ' << i << ' ' << nums[j] << ' ' << j << endl;
            if (2 * nums[i] <= nums[j]) {
                ++ans;
                --i;
                --j;
            } else {
                --i;
            }
        }
        return ans * 2;
    }
};

