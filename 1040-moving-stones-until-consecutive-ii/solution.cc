class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int spare_left = stones[n - 2] - stones[0] - n + 2;
        int spare_right = stones[n - 1] - stones[1] - n + 2;
        int ans_max = max(spare_left, spare_right);
        if (spare_left == 0 || spare_right == 0) {
            return { min(2, ans_max), ans_max };
        }
        int max_cnt = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            while (stones[left] <= stones[right] - n) {
                ++left;
            }
            max_cnt = max(max_cnt, right - left + 1);
        }
        return { n - max_cnt, ans_max };
    }
};

