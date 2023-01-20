class Solution {
    using ll = long long;
public:
    ll maxPower(vector<int>& stations, ll r, ll k) {
        ll n = stations.size();
        vector<ll> pref(n + 1), power(stations.begin(), stations.end());
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1] + power[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            power[i] = pref[min(i + r + 1, n)] - pref[max(0ll, i - r)];
        }

        auto check = [&](ll min_power) {
            vector<ll> d(n);
            ll sd = 0, need = 0;
            for (int i = 0; i < n; ++i) {
                sd += d[i];
                auto delta = min_power - power[i] - sd;
                if (delta > 0) {
                    need += delta;
                    if (need > k) return false;
                    sd += delta;
                    if (i + 2 * r + 1 < n) {
                        d[i + 2 * r + 1] -= delta;
                    }
                }
            }
            return true;
        };

        ll left = -1;
        ll right = pref.back() + k + 1;
        while (left + 1 < right) {
            ll mid = left + (right - left) / 2;
            if (check(mid))
                left = mid;
            else
                right = mid;
        }

        return left;
    }
};

