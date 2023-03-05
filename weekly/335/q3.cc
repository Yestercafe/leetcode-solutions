class Solution {
    using ll = long long;
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, ll> suff;
        vector<ll> cnt(n);
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            for (int f = 2; f <= sqrt(a) + 1; ++f) {
                while (a % f == 0) {
                    ++suff[f];
                    a /= f;
                }
            }
            if (a != 1) ++suff[a];
            cnt[i] = suff.size();
        }
        const int size = suff.size();

        for (int i = 0; i < n - 1; ++i) {
            int a = nums[i];
            for (int f = 2; f <= sqrt(a) + 1; ++f) {
                while (a % f == 0) {
                    --suff[f];
                    if (suff[f] == 0) suff.erase(f);
                    a /= f;
                }
            }
            if (a != 1) {
                --suff[a];
                if (suff[a] == 0) suff.erase(a);
            }
            if (cnt[i] + suff.size() == size) return i;
        }
        return -1;
    }
};

