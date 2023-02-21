constexpr int inf = 0x3f3f3f3f;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> ivs;
        for (int i = 0; i <= n; ++i) {
            ivs.push_back({
                max(0, i - ranges[i]),
                min(n, i + ranges[i])
            });
        }
        sort(ivs.begin(), ivs.end());
        int* f = new int[n + 1]{};
        memset(f + 1, 0x3f, sizeof(int) * n);
        for (auto [l, r] : ivs) {
            if (f[l] == inf) return -1;

            for (int i = l; i <= r; ++i) {
                f[i] = min(f[i], f[l] + 1);
            }
        }

        return f[n];
    }
};

