class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> c, cc;  // `count` of nums, `count` of "count of nums
        const int N = nums.size();
        int maxc = 0;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (c[nums[i]] > 0) {
                --cc[c[nums[i]]];
            }
            int new_c;
            ++cc[new_c = ++c[nums[i]]];
            maxc = max(maxc, new_c);
            if (false
                || maxc == 1  // 1 * everyone
                || cc[maxc] * maxc + 1 == i + 1  // maxc * everyone except anthoer + 1 * another
                || maxc + cc[maxc - 1] * (maxc - 1) == i + 1 // maxc * 1 anthoer + (maxc - 1) * everyone except another
            ) {
                ans = i + 1;
            }
        }
        return ans;
    }
};

