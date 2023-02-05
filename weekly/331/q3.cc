class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end()) - 1, r = *max_element(nums.begin(), nums.end()) + 1;
        
        auto check = [&](int maxx) {
            int cnt = 0;
            int cont_cnt = 0;
            for (auto a : nums) {
                if (a <= maxx) {
                    cont_cnt++;
                } else if (cont_cnt != 0) {
                    cnt += (cont_cnt + 1) / 2;
                    cont_cnt = 0;
                    if (cnt >= k) { break; }
                }
            }
            if (cont_cnt) {
                cnt += (cont_cnt + 1) / 2;
            }
            return cnt >= k;
        };
        
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
    }
};

