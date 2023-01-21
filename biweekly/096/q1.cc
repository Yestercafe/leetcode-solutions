class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for (int a : nums1) s1.insert(a);
        auto ans = -1;
        for (int a : nums2) s2.insert(a);
        for (int a : s2) {
            if (s1.find(a) != s1.end()) {
                ans = a;
                break;
            }
        }
        return ans;
    }
};

