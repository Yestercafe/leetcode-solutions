class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int md = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            md = max(md, nums[i + 1] - nums[i]);
        }
        int left = -1, right = md + 1;
        
        auto check = [&](int m) {
            bool used = false;
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (cnt >= p) {
                    return true;
                }
                if (used) {
                    used = false;
                    continue;
                }
                if (nums[i + 1] - nums[i] <= m) {
                    ++cnt;
                    used = true;
                }
            }
            if (cnt >= p) return true;
            return false;
        };
        
        while (left + 1 < right) {
            auto mid = left + (right - left) / 2;
            if (check(mid)) {
                // cout << left << ' ' << right << ' ' << mid << endl;
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return left + 1;
    }
};

