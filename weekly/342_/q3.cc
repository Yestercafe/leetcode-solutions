class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, const int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        int neg_cnt = 0;
        map<int, int> neg_cnts;
        for (int i = 0; i < k; ++i) {
            if (nums[i] < 0) {
                ++neg_cnt;
                ++neg_cnts[nums[i]];
            }
        }
        if (neg_cnt >= x) {
            int rem = x;
            for (auto [neg, ncnt] : neg_cnts) {
                rem -= ncnt;
                if (rem <= 0) {
                    ans[0] = neg;
                    break;
                }
            }
        }

        for (int i = k; i < n; ++i) {
            if (nums[i] < 0) {
                ++neg_cnt;
                ++neg_cnts[nums[i]];
            }
            if (nums[i - k] < 0) {
                --neg_cnt;
                --neg_cnts[nums[i - k]];
            }

            if (neg_cnt >= x) {
                int rem = x;
                for (auto [neg, ncnt] : neg_cnts) {
                    rem -= ncnt;
                    if (rem <= 0) {
                        ans[i - k + 1] = neg;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

