class Solution {
    using i64 = long long;
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int l = -1, r = start.back() + d + 1 - start.front();
        auto chk = [&](i64 m) {
            i64 s = start[0];
            int len = start.size();
            for (int i = 1; i < len; ++i) {
                if (1LL * start[i] + d - s < m) {
                    return false;
                }
                if (1LL * s + m < start[i]) {
                    s = start[i];
                } else {
                    s = s + m;
                }
            }
            return true;
        };
        while (l + 1 < r) {
            i64 mid = (1LL * l + r) / 2;
            if (chk(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

