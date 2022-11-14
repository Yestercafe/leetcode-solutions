class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            f[i][i] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            f[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int d = 2; d < n; ++d) {
            for (int i = 0; i + d < n; ++i) {
                if (!f[i + 1][i + d - 1]) continue;
                f[i][i + d] = (s[i] == s[i + d]);
            }
        }
        
        vector<int> f2(n + 1);
        for (int j = 1; j < n + 1; ++j) {
            f2[j] = f2[j - 1];
            if (j >= k) {
                for (int d = k; d <= j; ++d) {
                    if (f[j - d][j - 1]) {
                        f2[j] = max(f2[j], f2[j - d] + 1);
                    }
                }
            }
        }
        
        //for (auto& a : f2) cout << a << " ";
        //cout << endl;
        
        return f2.back();
    }
};

