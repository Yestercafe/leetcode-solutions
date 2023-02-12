class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (j == i) {
                ans += nums[i];
            } else {
                ans += stol(to_string(nums[i]) + to_string(nums[j]));
            }
            j--, i++;
        }
        return ans;
    }
};

