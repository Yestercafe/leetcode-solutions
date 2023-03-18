class Solution {
    using i64 = long long;
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int maxr = *max_element(ranks.begin(), ranks.end());
        i64 left = 0, right = (i64) maxr * cars * cars + 1;
        auto check = [&](i64 m) {
            int ncars = 0;
            for (int i = 0; i < n; ++i) {
                int r = ranks[i];
                ncars += int(sqrt(m / (double) r));
                if (ncars >= cars) return true;
            }
            if (ncars >= cars) return true;
            else return false;
        };
        while (left + 1 < right) {
            i64 mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};

