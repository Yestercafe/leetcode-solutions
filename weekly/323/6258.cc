class Solution {
    constexpr static int UPPER_BOUND = 1e5 + 5;
    using ll = long long;
public:
    int longestSquareStreak(vector<int>& nums) {
        set<ll> s;
        for (auto& a : nums) s.insert(a);
        int ans = -1;
        for (auto itr = s.begin(); itr != s.end(); s.erase(itr), ++itr) {
            int len = 1;
            ll n = *itr;
            while (n < UPPER_BOUND) {
                auto fnd = s.find(n * n);
                if (fnd == s.end()) break;
                s.erase(fnd);
                ++len;
                n *= n;
            }
            if (len > 1) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

