class Solution {
    using ll = long long;
    static ll powmod(ll a, ll b, ll p) {
        ll ans = 1 % p;
        for (; b; b >>= 1) {
            if (b & 1) ans = ans * a % p;
            a = a * a % p;
        }
        return ans;
    }
public:
    int countWays(vector<vector<int>>& ranges) {
        ll MOD = 1e9 + 7;
        sort(ranges.begin(), ranges.end());
        int cnt = 0;
        int e = -1;
        for (auto& r : ranges) {
            // cout << '[' << r[0] << ' ' << r[1] << ']' << ',';
            if (r[0] > e) {
                ++cnt;
            }
            e = max(e, r[1]);
        }
        return int(powmod(2, cnt, MOD));
    }
};

