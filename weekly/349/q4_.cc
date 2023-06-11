// 1404/1414, T
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& qs) {
        map<int, int> m1, m2;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            auto& y = m1[nums1[i]];
            y = max(y, nums2[i]);
            auto& x = m2[nums2[i]];
            x = max(x, nums1[i]);
        }
        vector<int> cox, coy;
        cox.reserve(n);
        coy.reserve(n);
        bool rev = false;
        if (m1.size() < m2.size()) {
            for (auto p : m1) {
                cox.push_back(p.first);
                coy.push_back(p.second);
            }
        } else {
            rev = true;
            for (auto p : m2) {
                cox.push_back(p.first);
                coy.push_back(p.second);
            }
        }
        vector<int> ans(qs.size(), -1);
        int nx = cox.size(), nq = qs.size();
        for (int k = 0; k < nq; ++k) {
            auto& q = qs[k];
            int x = q[0], y = q[1];
            if (rev) swap(x, y);
            int i = lower_bound(cox.begin(), cox.end(), x) - cox.begin();
            for (; i < nx; ++i) {
                if (coy[i] >= y) {
                    ans[k] = max(ans[k], cox[i] + coy[i]);
                }
            }
        }
        return ans;
    }
};

