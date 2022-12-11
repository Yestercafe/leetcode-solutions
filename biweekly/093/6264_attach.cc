class Solution {
    using ll = long long;
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        ll ans = 0;
        int mode, mode_cnt, part_cnt;
        mode = mode_cnt = part_cnt = 0;
        vector<int> cnts(n + 1);

        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                cnts[nums1[i]]++;
                part_cnt++;
                ans += i;
                if (cnts[nums1[i]] > mode_cnt) {
                    mode = nums1[i];
                    mode_cnt = cnts[nums1[i]];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (mode_cnt * 2 <= part_cnt) break;
            if (nums1[i] != nums2[i] && nums1[i] != mode && nums2[i] != mode) {
                ++part_cnt;
                ans += i;
            }
        }

        if (mode_cnt * 2 <= part_cnt)
            return ans;
        return -1;
    }
};

