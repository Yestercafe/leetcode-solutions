class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long pos = 0, neg = 0;
        for (int i = 0; i < n; ++i) {
            if (k == 0) {
                if (nums1[i] != nums2[i]) return -1;
                continue;
            }
            if ((nums1[i] - nums2[i]) % k != 0) {
                return -1;
            }
            if (nums1[i] - nums2[i] > 0) 
                pos += (nums1[i] - nums2[i]) / k;
            else
                neg += (nums2[i] - nums1[i]) / k;
        }
        if (pos != neg) return -1;
        return pos;
    }
};

