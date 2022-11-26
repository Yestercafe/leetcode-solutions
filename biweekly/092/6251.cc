class Solution {
    static constexpr int M = 1e9 + 7;
    long long lc[100], rc[100], lc1[10], rc1[10];
public:
    int countPalindromes(string s) {
        if (s.length() < 5) return 0;
        int n = s.length();
        for (int i = 3; i < n; ++i) {
            ++rc1[s[i] - '0'];
            for (int j = i + 1; j < n; ++j) {
                rc[10 * (s[i] - '0') + (s[j] - '0')]++;
            }
        }
        int p = 2;
        lc[10 * (s[0] - '0') + (s[1] - '0')]++;
        lc1[s[0] - '0']++;
        lc1[s[1] - '0']++;

        
        long long ans = 0;
        while (p < n - 2) {
            for (int i = 0; i < 10; ++i) {   // 100
                for (int j = 0; j < 10; ++j) {
                    ans = (ans + ((lc[i * 10 + j] % M) * (rc[j * 10 + i] % M)) % M) % M;
                }
            }
            ++p;
            
            --rc1[s[p] - '0'];
            for (int i = 0; i < 10; ++i) {
                // left add, right sub
                lc[i * 10 + (s[p - 1] - '0')] += lc1[i];
                rc[(s[p] - '0') * 10 + i] -= rc1[i];
            }
            ++lc1[s[p - 1] - '0'];
        }
        return ans;
    }
};

