class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int c1[10] {};
        int c2[10] {};
        for (int i : nums1) c1[i] = 1;
        for (int i : nums2) c2[i] = 1;
        for (int i = 0; i < 10; ++i) {
            if (c1[i] && c2[i]) return i;
        }
        
        int m1 = *min_element(nums1.begin(), nums1.end());
        int m2 = *min_element(nums2.begin(), nums2.end());
        if (m1 == m2) return m1;
        if (m1 > m2) swap(m1, m2);
        return m1 * 10 + m2;
    }
};

