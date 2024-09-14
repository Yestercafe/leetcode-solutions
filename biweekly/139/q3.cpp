class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        const int max_n = (1 << 7) - 1;
        vector<vector<vector<int>>> pref, suff;
        pref = suff = vector(n, vector(k + 1, vector(max_n + 1, 0)));
        pref[0][0][0] = 1;
        pref[0][1][nums[0]] = 1;
        suff[n - 1][0][0] = 1;
        suff[n - 1][1][nums[n - 1]] = 1;
        
        for (int i = 1; i < n - k; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int m = 0; m <= max_n; ++m) {
                    pref[i][j][m] = pref[i - 1][j][m];
                }
            }

            for (int j = 0; j < k; ++j) {
                for (int m = 0; m <= max_n; ++m) {
                    if (pref[i - 1][j][m]) {
                        pref[i][j + 1][m | nums[i]] = 1;
                    }
                }
            }
        }

        for (int I = 1; I < n - k; ++I) {
            int i = (n - 1) - I;
            for (int j = 0; j <= k; ++j) {
                for (int m = 0; m <= max_n; ++m) {
                    suff[i][j][m] = suff[i + 1][j][m];
                }
            }

            for (int j = 0; j < k; ++j) {
                for (int m = 0; m <= max_n; ++m) {
                    if (suff[i + 1][j][m]) {
                        suff[i][j + 1][m | nums[i]] = 1;
                    }
                }
            }
        }

        int ans;
        bool gotResult = false;
        for (ans = max_n; ans > 0; --ans) {
            for (int i = k - 1; i < n - k; ++i) {
                for (int m = 0; m <= max_n; ++m) {
                    if (pref[i][k][m] && suff[i + 1][k][ans ^ m]) {
                        gotResult = true;
                        break;
                    }
                }
                if (gotResult) break;
            }
            if (gotResult) break;
        }
        return ans;
    }
};

