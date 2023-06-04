class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        if (nums.front() == 1 && nums.back() == n) return 0;
        auto p1 = find(nums.begin(), nums.end(), 1) - nums.begin();
        auto pn = find(nums.begin(), nums.end(), n) - nums.begin();
        if (p1 == 0) {
            return n - 1 - pn;
        }
        if (pn == n - 1) {
            return p1;
        }
        
        if (p1 < pn) {
            return n - 1 - pn + p1;
        } else {
            return n - 1 - pn + p1 - 1;
        }
    }
};

