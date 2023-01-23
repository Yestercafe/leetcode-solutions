class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n + 1);
        
        for (int i = 0; i < n; ++i) {
            int trimmed = 0;
            vector<int> cnt(n);
            int minn = 123456789;
            for (int j = i; j >= 0; --j) {
                auto c = ++cnt[nums[j]];
                if (c == 2) {
                    trimmed += 2;
                } else if (c > 2) {
                    trimmed += 1;
                }
                minn = min(minn, trimmed + f[j]);
            }
            f[i + 1] = k + minn;
        }

        return f[n];
    }
};

