class Solution {
    using i64 = long long;
public:
    long long continuousSubarrays(vector<int>& nums) {
        i64 ans = 0;
        map<int, int> mi, ma;
        auto minn = [&](int x) {
            if (mi.empty()) return x;
            return mi.begin()->first;
        };
        auto maxx = [&](int x) {
            if (ma.empty()) return x;
            return -ma.begin()->first;
        };
        auto insert = [&](int x) {
            ++mi[x];
            ++ma[-x];
        };
        auto erase = [&](int x) {
            auto mip = mi.find(x);
            if (--mip->second == 0) mi.erase(mip);
            auto map = ma.find(-x);
            if (--map->second == 0) ma.erase(map);
        };
        int n = nums.size(), i = 0, j = 0;
        while (j < n) {
            while (j < n && _abs(nums[j] - minn(nums[j])) <= 2 && _abs(nums[j] - maxx(nums[j])) <= 2) {
                insert(nums[j]);
                ++j;
                ans += j - i;
            }
            if (i < n && i < j) {
                erase(nums[i]);
                ++i;
            }
        }

        return ans;
    }

    static int _abs(int x) {
        return x < 0 ? -x : x;
    }
};

