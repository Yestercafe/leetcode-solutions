class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int f = to_string(nums[i]).front() - '0';
                int b = to_string(nums[j]).back() - '0';
                if (gcd(f, b) == 1) {
                    ans++;                    
                }
            }
        }
        return ans;
    }
};

