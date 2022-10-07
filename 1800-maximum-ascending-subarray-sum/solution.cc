class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0, cur_sum = 0;
        int prev = INT_MAX;
        for (auto& a : nums) {
            if (a <= prev) {
                max_sum = max(max_sum, cur_sum);
                cur_sum = 0;
            }
            cur_sum += a;
            prev = a;
        }
        max_sum = max(max_sum, cur_sum);
        return max_sum;
    }
};

