class Solution {
    bool is_prime(int n) {
        if (n == 1) return false;
        int sr = sqrt(n) + 1;
        for (int f = 2; f < n && f <= sr; ++f) {
            if (n % f == 0) return false;
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int max_prime = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (is_prime(nums[i][i])) {
                max_prime = max(max_prime, nums[i][i]);
            }
            if (is_prime(nums[i][n - 1 - i])) {
                max_prime = max(max_prime, nums[i][n - 1 - i]);
            }
        }
        return max_prime;
    }
};

