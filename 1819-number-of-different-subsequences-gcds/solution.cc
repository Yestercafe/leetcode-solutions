class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxx = *max_element(nums.cbegin(), nums.cend());
        vector<bool> v(maxx + 1);
        for (auto&& n : nums) v[n] = true;
        int ans = 0;
        for (int i = 1; i <= maxx; ++i) {
            int g = 0;
            for (int j = i; j <= maxx; j += i) {
                if (v[j]) {
                    g = gcd(g, j);
                    if (g == i) {
                        ++ans;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

