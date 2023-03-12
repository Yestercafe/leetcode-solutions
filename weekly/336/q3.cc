class Solution {
    using i64 = long long;
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, i64> cnt;
        i64 ans = 0;
        int pref = 0;
        ++cnt[0];
        for (auto n : nums) {
            pref ^= n;
            ans += cnt[pref];
            ++cnt[pref];
        }
        return ans;
    }
};

