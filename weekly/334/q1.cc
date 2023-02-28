class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n + 1), r(n + 1);
        partial_sum(nums.begin(), nums.end(), l.begin() + 1);
        partial_sum(nums.rbegin(), nums.rend(), r.begin() + 1);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = abs(l[i] - r[n - 1 - i]);
        }
        return ans;
    }
};

