class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        vector<long long> a1, a2;
        for (auto n : nums) {
            if (n > 0) {
                a1.push_back(n);
            } else if (n < 0) {
                a2.push_back(-n);
            }
        }
        sort(a1.begin(), a1.end(), greater<>{});
        sort(a2.begin(), a2.end(), greater<>{});
        long long ans = accumulate(a1.begin(), a1.end(), 1LL, multiplies<>{});
        for (int i = 0; i < a2.size() / 2 * 2; ++i) {
            ans *= a2[i];
        }
        
        if (a2.size() / 2 * 2 == 0 && a1.size() == 0) {
            return *max_element(nums.begin(), nums.end());
        }
        
        return ans;
    }
};

