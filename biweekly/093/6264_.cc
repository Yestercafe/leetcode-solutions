// not finish
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> same;
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                same.push_back(i);
            }
        }
        
        vector<bool> swapped(n, false);
        int m = same.size();
        int ans = 0;
        if (m & 1) {
            for (int i = 0; i < m; ++i) {
                if (swapped[same[i]]) continue;
                int j;
                bool used = false;
                for (j = 0; j < m; ++j) {
                    if (!swapped[same[j]] && nums1[same[i]] != nums1[same[j]]) {
                        swapped[same[j]] = swapped[same[i]] = true;
                        ans += same[i] + same[j];
                        break;
                    }
                }
                if (j == m) {
                    if (used) return -1;
                    used = true;
                    for (int j = 0; j < n; ++j) {
                        if (nums1[same[i]] != nums1[j] && nums1[same[i]] != nums2[j]) {
                            swapped[same[i]] = true;
                            ans += same[i] + j;
                            break;
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < m; ++i) {
                if (swapped[same[i]]) continue;
                int j;
                for (j = 0; j < m; ++j) {
                    if (!swapped[same[j]] && nums1[same[i]] != nums1[same[j]]) {
                        swapped[same[j]] = swapped[same[i]] = true;
                        ans += same[i] + same[j];
                        break;
                    }
                }
                if (j == m) return -1;
            }
        }
        return ans;
    }
};

