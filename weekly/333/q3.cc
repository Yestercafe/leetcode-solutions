class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int MOD = 1e9 + 7;
        unordered_map<int, int> idx {{2, 1}, {3, 1<<1}, {5, 1<<2}, {7, 1<<3}, {11, 1<<4}, {13, 1<<5}, {17, 1<<6}, {19, 1<<7}, {23, 1<<8}, {29, 1<<9}};
        int n = nums.size();
        vector f(n + 1, vector(1024, 0ll));
        int ones = 0;
        
        for (int i = 0; i < n; ++i) {
            // for (int j = 0; j <= 6; ++j) {
            //     cout << f[i][j] << ' ';
            // }
            // cout << endl;
            int k = nums[i];
            if (k == 1) {
                for (int j = 0; j < 1024; ++j) {
                    f[i + 1][j] = f[i][j];
                }
                ones++;
                continue;
            }
            if (k % 4 == 0 || k % 9 == 0 || k % 25 == 0) {   // 比赛的时候漏了 25
                for (int j = 0; j < 1024; ++j) {
                    f[i + 1][j] = f[i][j];
                }
                continue;
            }
            
            int mask = 0;
            for (int a = 2; a <= 30; a++) {
                if (k % a == 0) {
                    mask |= idx[a];
                    k /= a;
                }
            }
    
            f[i + 1][mask]++;
            mask ^= 1023;
            
            for (int j = 0; j < 1024; ++j) {
                // unselect
                f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
                // select
                if ((mask | j) == mask) {
                    int m = (mask ^ 1023);
                    f[i + 1][(mask ^ 1023) | j] = (f[i + 1][(mask ^ 1023) | j] + f[i][j]) % MOD;
                }
            }
        }
        
        // for (int j = 0; j <= 6; ++j) {
        //     cout << f.back()[j] << ' ';
        // }
        
        int sum = 0;
        for (int i = 0; i < 1024; ++i) {
            sum = (sum + f.back()[i]) % MOD;
        }
        for (int i = 0; i < ones; ++i) {
            sum = (2 * sum + 1) % MOD;
        }
        return sum;
    }
};

