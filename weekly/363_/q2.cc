class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        int maxx = -1;
        map<int, int> cnt;
        for (auto a : nums) {
            ++cnt[a];
            maxx = max(maxx, a);
        }

        int ans = 0;
        int cnt_sel = 0;
        cnt[INT_MAX] = 0;
        if (cnt.count(0) == 0) {
            ++ans;
        }
        auto it = cnt.begin();
        int nn = cnt.size();

        for (int i = 0; i < nn - 1; ++i) {
            auto [a, c] = *it++;
            cnt_sel += c;
            if (a < cnt_sel && cnt_sel < it->first) {
                ++ans;
            }
        }
        
        if (cnt_sel < maxx) ++ans;

        return ans;
    }
};

