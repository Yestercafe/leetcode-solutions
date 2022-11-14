class Solution {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        
        int cnt = 0;
        for (auto& a : nums) {
            if (a == k) ++cnt;
        }
        for (int i = 0; i < n - 1; ++i) {
            if ((f[i][i + 1] = nums[i] / gcd(nums[i], nums[i + 1]) * nums[i + 1]) == k) {
                ++cnt;
            }
        }
        
        for (int d = 2; d < n; ++d) {
            for (int i = 0; i + d < n; ++i) {
                if (f[i][i + d - 1] == 0) {
                    f[i][i + d] = 0;
                } else if (f[i][i + d - 1] == k) {
                    if (k % nums[i + d] == 0) {
                        f[i][i + d] = k;
                        ++cnt;
                    } else {
                        f[i][i + d] = 0;
                    }
                } else {
                    int lcm = f[i][i + d - 1] / gcd(f[i][i + d - 1], nums[i + d]) * nums[i + d];
                    if (lcm == k) {
                        f[i][i + d] = lcm;
                        ++cnt;
                    } else if (lcm < k) {
                        f[i][i + d] = lcm;
                    } else {
                        f[i][i + d] = 0;
                    }
                }
            }
        }
        
        return cnt;
    }
};

