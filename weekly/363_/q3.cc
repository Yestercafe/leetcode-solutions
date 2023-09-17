class Solution {
    using i64 = long long;
public:
    int maxNumberOfAlloys(int n, int k, int bt, vector<vector<int>>& cn, vector<int>& sk, vector<int>& ct) {
        i64 left = -1, right = 3e8;

        auto check = [&](i64 m) {
            for (int i = 0; i < k; ++i) {
                i64 cost = 0;
                for (int j = 0; j < n; ++j) {
                    cost += ct[j] * clamp(m * cn[i][j] - sk[j], 0LL, m * cn[i][j]);
                }
                if (cost <= bt) {
                    return true;
                }
            }
            return false;
        };

        while (left + 1 < right) {
            i64 mid = left + right >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

