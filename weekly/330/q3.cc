class Solution {
    using ll = long long;
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == n) return 0;
        vector<ll> v(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            v[i] = weights[i] + weights[i + 1];
        }
        sort(v.begin(), v.end());

        ll ans = 0;
        for (int i = 0; i < k - 1; ++i) {
            ans = ans + *(v.rbegin() + i) - *(v.begin() + i);
        }
        return ans;
    }
};

